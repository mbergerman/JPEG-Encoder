from bitstring import BitArray
from dqt_tables import *
from vectorize import Vectorize
from DHT import *
import numpy as np

def jfif(vector, rows, cols, luma_tbl, chroma_tbl, chroma_subsampling=(2,2)):
    file = BitArray()
    file += BitArray('0xFFD8') #start of image

    """ APP0 """
    file += BitArray('0xFFE0') #app0 marker
    file += BitArray('0x0010') #length of 16 bytes for app0 excluding app0 marker
    file += BitArray(b'JFIF\0') #jfif en ascii
    file += BitArray('0x0101') #research jfif version
    file += BitArray('0x00') # no unit
    file += BitArray('0x00010001') # pixel density 1
    file += BitArray('0x0000')
    
    """ DQT """
    file += BitArray('0xFFDB')
    file += BitArray('0x0043') #2+65=67 bytes of length
    file += BitArray('0x00') #Pq=0 (8bits) y Tq=0 
    v = Vectorize()
    zigzag_dqt_luma = v.zigzag(luma_tbl).astype(np.uint8)
    for k in zigzag_dqt_luma:
        file += BitArray(bytes([k]))

    file += BitArray('0xFFDB')
    file += BitArray('0x0043') #2+65=67 bytes of length
    file += BitArray('0x01') #Pq=0 (8bits) y Tq=1 
    v = Vectorize()
    zigzag_dqt_luma = v.zigzag(chroma_tbl).astype(np.uint8)
    for k in zigzag_dqt_luma:
        file += BitArray(bytes([k]))

    """ Component specifications' parameters """
    file += BitArray('0xFFC0') #DCT Baseline
    file += BitArray('0x0011') #length
    file += BitArray('0x08') #precision

    file += BitArray(rows.to_bytes(2,byteorder='big'))
    file += BitArray(cols.to_bytes(2,byteorder='big'))

    file += BitArray('0x03') #number of components

    #component 1 = Y
    file += BitArray('0x01') #component 1
    ss_x, ss_y = chroma_subsampling
    file += BitArray(bytes([ss_x<<4 | ss_y])) #Y sampling factor H<<4|V
    file += BitArray('0x00') #Tq = 0 (quatization table 0 -> DQT_LUMA)
    #component 2 = Cb
    file += BitArray('0x02')
    file += BitArray('0x11') #chroma sampling factor = 1,1
    file += BitArray('0x01') #Tq = 1 (quatization table 1 -> DQT_CHROMA)
    #component 3 = Cr
    file += BitArray('0x03')
    file += BitArray('0x11') #chroma sampling factor = 1,1
    file += BitArray('0x01') #Tq = 1 (quatization table 1 -> DQT_CHROMA)

    """ DHT Huffman Tables """

    #HUFFMAN TABLES FOR LUMA
    # DC LUMA
    file += BitArray('0xFFC4')
    file += BitArray('0x001F') #length 31 bytes
    file += BitArray(bytes([0<<4 | 0])) #table class dc = 0 y table id = 0

    # lambda function for getting the amount of codes with certain length 
    get_ncodes = lambda length, table: len(list(filter(lambda x: x==length,map(len,table))))
    
    # add number of codes with length n
    for n in range(1,17):
        file += BitArray(bytes([get_ncodes(n,Y_DC_DECODE)]))
    # add categories in order according to length
    for category in sorted(Y_DC_ENCODE, key = lambda x: len(Y_DC_ENCODE[x])):
        file += BitArray(bytes([category]))

    # AC LUMA
    file += BitArray('0xFFC4')
    file += BitArray('0x00B5') #length 181 bytes
    file += BitArray(bytes([1<<4 | 0])) #table class ac = 1 y table id = 0

    # add number of codes with length n
    for n in range(1,17):
        file += BitArray(bytes([get_ncodes(n, Y_AC_DECODE)]))
    # add run/category pairs in order according to length
    for code in sorted(Y_AC_ENCODE, key = lambda x: len(Y_AC_ENCODE[x])):
        run, cat = code
        file += BitArray(bytes([run<<4 | cat]))

    # HUFFMAN TABLES FOR CHROMA
    # DC CHROMA
    file += BitArray('0xFFC4')
    file += BitArray('0x001F') #length 31 bytes
    file += BitArray(bytes([0<<4 | 1])) #table class dc = 0 y table id = 1

    # add number of codes with length n
    for n in range(1,17):
        file += BitArray(bytes([get_ncodes(n,CH_DC_DECODE)]))
    # add categories in order according to length
    for category in sorted(CH_DC_ENCODE, key = lambda x: len(CH_DC_ENCODE[x])):
        file += BitArray(bytes([category]))

    # AC CHROMA
    file += BitArray('0xFFC4')
    file += BitArray('0x00B5') #length 181 bytes
    file += BitArray(bytes([1<<4 | 1])) #table class ac = 1 y table id = 1

    # add number of codes with length n
    for n in range(1,17):
        file += BitArray(bytes([get_ncodes(n, CH_AC_DECODE)]))
    # add run/category pairs in order according to length
    for code in sorted(CH_AC_ENCODE, key = lambda x: len(CH_AC_ENCODE[x])):
        run, cat = code
        file += BitArray(bytes([run<<4 | cat]))

    """ SOS Start of Scan """
    file += BitArray('0xFFDA')
    file += BitArray('0x000C') #length 12 bytes
    file += BitArray('0x03') # number of image components

    # select component 1 = Y
    file += BitArray('0x01')
    file += BitArray(bytes([0<<4 | 0])) #select huffman table dc<<4|ac
    # select component 2 = Cb
    file += BitArray('0x02')
    file += BitArray(bytes([1<<4 | 1])) #select huffman table dc<<4|ac
    # select component 3 = Cr
    file += BitArray('0x03')
    file += BitArray(bytes([1<<4 | 1])) #select huffman table dc<<4|ac


    file += BitArray('0x00') #start of spectral predictor selectral -> set to zero
    file += BitArray('0x3F') #end of spectral predictor selectral -> set to 63
    file += BitArray('0x00') #successive approximation bit position high and low Ah | Al


    file += vector


    # THE END
    file += BitArray('0xFFD9')

    return file
