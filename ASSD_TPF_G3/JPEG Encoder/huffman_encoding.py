import numpy as np
from bitstring import BitArray
from huffman_tables import *
from zigzag_scan import unzigzag_scan, zigzag_scan

def huffman_encoding(im_dqt_y, im_dqt_cb, im_dqt_cr, subsampling=1, block_size=8):
    rows, cols = np.shape(im_dqt_y)
    dc_prev_1 = 0
    dc_prev_2 = 0
    dc_prev_3 = 0
    vector = BitArray()
    for j in range(0, rows, subsampling*block_size):
        for i in range(0, cols, subsampling*block_size):
            block10 = im_dqt_y[j:j+block_size, i:i+block_size]
            if subsampling==2:
                block11 = im_dqt_y[j:j+block_size, i+block_size:i+subsampling*block_size]
                block12 = im_dqt_y[j+block_size:j+subsampling*block_size, i:i+block_size]
                block13 = im_dqt_y[j+block_size:j+subsampling*block_size, i+block_size:i+subsampling*block_size]

            row = j//subsampling
            col = i//subsampling
            block2 = im_dqt_cb[row:row+block_size, col:col+block_size]
            block3 = im_dqt_cr[row:row+block_size, col:col+block_size]

            # send 4 blocks of luma
            vector += huffman_block(block10, dc_prev_1, Y_DC_ENCODE, Y_AC_ENCODE)
            dc_prev_1 = block10[0][0]
            if subsampling == 2:
                vector += huffman_block(block11, dc_prev_1, Y_DC_ENCODE, Y_AC_ENCODE)
                dc_prev_1 = block11[0][0]
                vector += huffman_block(block12, dc_prev_1, Y_DC_ENCODE, Y_AC_ENCODE)
                dc_prev_1 = block12[0][0]
                vector += huffman_block(block13, dc_prev_1, Y_DC_ENCODE, Y_AC_ENCODE)
                dc_prev_1 = block13[0][0]

            # send 1 block of chroma
            vector += huffman_block(block2, dc_prev_2, CH_DC_ENCODE, CH_AC_ENCODE)
            dc_prev_2 = block2[0][0]
            vector += huffman_block(block3, dc_prev_3, CH_DC_ENCODE, CH_AC_ENCODE)
            dc_prev_3 = block3[0][0]

    while len(vector)%8 != 0:
        vector += BitArray('0b1')
        
    vector_stuffed = BitArray()
    for k in range(0,len(vector),8):
        vector_stuffed += vector[k:k+8] if vector[k:k+8]!=BitArray('0xff') else BitArray('0xff00')
        
    return vector_stuffed

def huffman_block(block,dc_prev,DC_ENCODE,AC_ENCODE):
    block_bits = BitArray()
    
    v = zigzag_scan(block)

    #differential encoding
    dc = int(v[0]) - dc_prev #compute difference
    dc_prev = int(v[0]) #save for next block
    
    dc_abs = int(abs(dc))
    dc_bits = BitArray(bin(dc_abs))
    dc_bits = dc_bits if dc>=0 else ~dc_bits
    cat = len(dc_bits) if dc_abs>0 else 0
    size_bits = BitArray('0b'+DC_ENCODE[cat])
    if cat>0:
        block_bits += size_bits + dc_bits
    else:
        block_bits += size_bits

    #run length encoding
    run = 0
    for k in range(1,64):
        ac = int(v[k])
        if ac == 0:
            run += 1
            if run>15:
                code_bits = BitArray('0b'+AC_ENCODE[15,0])
                run -= 16
                block_bits += code_bits
        else: 
            ac_abs = abs(ac)
            ac_bits = BitArray(bin(ac_abs))
            ac_bits = ac_bits if ac>=0 else ~ac_bits
            cat = len(ac_bits)
            code_bits = BitArray('0b'+AC_ENCODE[run,cat])
            block_bits += code_bits + ac_bits
            run = 0 
    if run != 0:
        block_bits += BitArray('0b1010') #end of block      

    return block_bits

def huffman_decoding(bits: BitArray, rows:int, cols:int,  block_size = 8):
    s = 0
    e = 2
    dc_prev = 0
    index = 0
    im = np.zeros([rows,cols])
    for j in range(0, rows, block_size):
        for i in range(0, cols, block_size):
            v = np.array([])
            #decode dc component
            while True:
                code = bits[s:e].bin
                if code in Y_DC_DECODE:
                    cat = Y_DC_DECODE[code]
                    if cat == 0:
                        mag = 0 + dc_prev
                    elif bits[e]:
                        mag = int(bits[e:e+cat].bin,2) + dc_prev
                        dc_prev = mag
                    else:
                        mag = -int((~bits[e:e+cat]).bin,2) + dc_prev
                        dc_prev = mag
                    v = np.append(v,[mag])
                    s = e+cat
                    e = s+2
                    break
                else:
                    e += 1

            #decode ac components
            while np.size(v)<64:
                code = bits[s:e].bin
                if code in Y_AC_DECODE:
                    run, cat = Y_AC_DECODE[code]
                    if (run,cat) == (0,0): #end of block! complete with zeros and break loop
                        v = np.append(v,np.zeros(64-np.size(v)))
                        s = e
                        e = s+2
                        break
                    z = 16 if (run,cat) == (15,0) else run
                    v = np.append(v,np.zeros(z))
                    if cat and bits[e]:
                        mag = int(bits[e:e+cat].bin,2)
                        v = np.append(v,[mag])
                    elif cat:
                        mag = -int((~bits[e:e+cat]).bin,2)
                        v = np.append(v,[mag])
                    s = e+cat
                    e = s+2
                else:
                    e+=1

            block = unzigzag_scan(v)
            
            # add to matrix (need to know width and height)
            im[j:j+block_size, i:i+block_size] = block
    return im