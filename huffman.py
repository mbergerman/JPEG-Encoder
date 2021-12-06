import numpy as np
from vectorize import Vectorize
from bitstring import BitArray
from Y_TABLES import *

def huffman_encoding(im, block_size=8):
    rows, cols = np.shape(im)
    dc_prev = 0
    block_bits = BitArray()
    for j in range(0, rows, block_size):
        for i in range(0, cols, block_size):
            block = im[j:j+block_size, i:i+block_size]
            v = Vectorize()
            v = v.zigzag(block)

            #differential encoding
            dc = int(v[0]) - dc_prev #compute difference
            dc_prev = int(v[0]) #save for next block
            
            dc_abs = abs(dc)
            dc_bits = BitArray(bin(dc_abs))
            dc_bits = dc_bits if dc>=0 else ~dc_bits
            cat = len(dc_bits) if dc_abs>0 else 0
            size_bits = BitArray('0b'+Y_DC_ENCODE[cat])
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
                        code_bits = BitArray('0b'+Y_AC_ENCODE[15,0])
                        run -= 16
                        block_bits += code_bits
                else: 
                    ac_abs = abs(ac)
                    ac_bits = BitArray(bin(ac_abs))
                    ac_bits = ac_bits if ac>=0 else ~ac_bits
                    cat = len(ac_bits)
                    code_bits = BitArray('0b'+Y_AC_ENCODE[run,cat])
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

            # unzigzag v 
            vectorize = Vectorize()
            block = vectorize.unzigzag(v, block_size, block_size) 
            # add to matrix (need to know width and height)
            im[j:j+block_size, i:i+block_size] = block
    return im