import matplotlib.pyplot as plt
import imageio as iio
import numpy as np
from scipy.fft import dct, idct
from ycbcr import *
from dqt import *

im = iio.imread('chelsea.png')
im_ybr = rgb2ycbcr(im)

im_jpeg = np.zeros((im_ybr.shape[0], im_ybr.shape[1]))

for y in range(0, len(im_ybr), 8):
    for x in range(0, len(im_ybr[0]), 8):
        block_y = im_ybr[y:y+8, x:x+8, 0]
        block_shifted = np.subtract(block_y, 128, dtype=np.int8)

        block_dct = dct(block_shifted)
        block_dct = np.round(block_dct / dqt)

        im_jpeg[y:y+8, x:x+8] = block_dct


# Decoder:

im_out = np.zeros((im_jpeg.shape[0], im_jpeg.shape[1]))

for y in range(0, len(im_jpeg), 8):
    for x in range(0, len(im_jpeg[0]), 8):

        block_dct = im_jpeg[y:y+8, x:x+8] * dqt

        block_idct = idct(block_dct).astype(np.int8)
        im_out[y:y+8, x:x+8] = np.add(block_idct, 128).astype(np.uint8)

plt.imshow(im_out, cmap='gray')
plt.show()

iio.imsave('output.png', im_out)