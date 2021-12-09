import numpy as np
from dct import *
from dct_tables import *

def dct_quantization(im, dqt = DQT_LUMA_50, block_size = 8):
    im_out = np.zeros_like(im, dtype=np.float64)

    for j in range(0, len(im), block_size):
        for i in range(0, len(im[0]), block_size):
            block = im[j:j+block_size, i:i+block_size]
            block_shifted = np.subtract(block, 128, dtype=np.int8)  # Cast to signed integers

            block_dct = dct(block_shifted)
            block_dct_q = np.round(block_dct / dqt)
        
            im_out[j:j+block_size, i:i+block_size] = block_dct_q

    return im_out
