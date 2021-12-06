import matplotlib.pyplot as plt
import imageio as iio
import numpy as np
from downsample import downsample, upsample
from ycbcr import *
from dqt import *
from decode import *
from huffman import huffman_decoding, huffman_encoding

# Open original image
im = iio.imread('chelsea.png')

# Convert RGB data to the Y'CbCr color space
im_ybr = rgb2ycbcr(im)

# Perform chroma subsampling 4:2:0 (2x2)
im_y = downsample(im_ybr[:, :, 0], 1, 1).astype(np.uint8)
im_cb = downsample(im_ybr[:, :, 1], 2, 2).astype(np.uint8)
im_cr = downsample(im_ybr[:, :, 2], 2, 2).astype(np.uint8)

# Perform DCT and Quantization
im_dqt_y = dct_dqt(im_y, DQT_LUMA, 8)
im_dqt_cb = dct_dqt(im_cb, DQT_CHROMA, 8)
im_dqt_cr = dct_dqt(im_cr, DQT_CHROMA, 8)

#Perfom Huffman encoding
vectors = []
v_huff_y = huffman_encoding(im_dqt_y,8,vectors)
im_dehuff_y = huffman_decoding(v_huff_y, *np.shape(im_dqt_y), vectors)
## Decoder ##

# Decode the image
im_out_y = decode_jpeg(im_dehuff_y, DQT_LUMA, 8)
im_out_cb = decode_jpeg(im_dqt_cb, DQT_CHROMA, 8)
im_out_cr = decode_jpeg(im_dqt_cr, DQT_CHROMA, 8)

# Upsample using the nearest neighbour algorithm
im_out_y = upsample(im_out_y, 1, 1)
im_out_cb = upsample(im_out_cb, 2, 2)
im_out_cr = upsample(im_out_cr, 2, 2)

# Reconstruct RGB image
im_out_ybr = np.dstack((im_out_y, im_out_cb, im_out_cr))
im_out_rgb = ycbcr2rgb(im_out_ybr)

# Auxiliary images for displaying purposes
im_ones = np.ones((im.shape[0], im.shape[1]))
im_cb_rgb = ycbcr2rgb(np.dstack((im_ones*128, im_out_cb, im_ones*128)))
im_cr_rgb = ycbcr2rgb(np.dstack((im_ones*128, im_ones*128, im_out_cr)))

fig, ax = plt.subplots(2, 3, figsize=(12, 6), sharex=True, sharey=True)
ax[0,0].imshow(im_out_rgb)
ax[0,0].set_title('Decoded Image')
ax[1,0].imshow(im_out_y, cmap='gray')
ax[1,0].set_title('Y\' component')
ax[0,1].imshow(im_cb_rgb)
ax[0,1].set_title('Cb component')
ax[1,1].imshow(im_cr_rgb)
ax[1,1].set_title('Cr component')
ax[0,2].imshow(im_out_cb, cmap='gray')
ax[0,2].set_title('Cb component (grayscale)')
ax[1,2].imshow(im_out_cr, cmap='gray')
ax[1,2].set_title('Cr component (grayscale)')

plt.savefig('plot.png', dpi=600)
plt.show()


# fig, ax = plt.subplots(1,2, figsize=(12,6), sharex=True, sharey=True)
# ax[0].imshow(im_out_rgb)
# ax[0].set_title('Decoded Image')
# ax[1].imshow(im)
# ax[1].set_title('Original')
# plt.show()
