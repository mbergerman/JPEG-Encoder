import numpy as np
from dct import *

#https://www.impulseadventure.com/photo/jpeg-quantization.html

DQT_LUMA = np.array(   [[16, 11, 10, 16, 24,  40,  51,  61 ],
                        [12, 12, 14, 19, 26,  58,  60,  55 ],
                        [14, 13, 16, 24, 40,  57,  69,  56 ],
                        [14, 17, 22, 29, 51,  87,  80,  62 ],
                        [18, 22, 37, 56, 68,  109, 103, 77 ],
                        [24, 35, 55, 64, 81,  104, 113, 92 ],
                        [49, 64, 78, 87, 103, 121, 120, 101],
                        [72, 92, 95, 98, 112, 100, 103, 99 ] ])
          
DQT_CHROMA = np.array( [[17, 18, 24, 47, 99, 99, 99, 99],
                        [18, 21, 26, 66, 99, 99, 99, 99],
                        [24, 26, 56, 99, 99, 99, 99, 99],
                        [47, 66, 99, 99, 99, 99, 99, 99],
                        [99, 99, 99, 99, 99, 99, 99, 99],
                        [99, 99, 99, 99, 99, 99, 99, 99],
                        [99, 99, 99, 99, 99, 99, 99, 99],
                        [99, 99, 99, 99, 99, 99, 99, 99] ])

def dct_dqt(im, dqt = DQT_LUMA, block_size = 8):
    im_out = np.zeros_like(im, dtype=np.float64)

    for j in range(0, len(im), block_size):
        for i in range(0, len(im[0]), block_size):
            block = im[j:j+block_size, i:i+block_size]
            block_shifted = np.subtract(block, 128, dtype=np.int8)  # Cast to signed integers

            block_dct = dct(block_shifted)
            block_dct_q = np.round(block_dct / dqt)
        
            im_out[j:j+block_size, i:i+block_size] = block_dct_q

    return im_out
