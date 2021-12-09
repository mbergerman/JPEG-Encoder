import imageio as iio
import matplotlib.pyplot as plt
from subsampling import subsample, upsample
from ycbcr import *

im = iio.imread('chelsea_eye.png')

# Convert RGB data to the YCbCr color space
im_ybr = rgb2ycbcr(im)

s = 2 #subsampling en chroma
im_y = subsample(im_ybr[:, :, 0], 1, 1).astype(np.uint8)
im_cb = subsample(im_ybr[:, :, 1], s, s).astype(np.uint8)
im_cr = subsample(im_ybr[:, :, 2], s, s).astype(np.uint8)

# Upsample using the nearest neighbour algorithm
im_y = upsample(im_y, 1, 1)
im_cb = upsample(im_cb, 2, 2)
im_cr = upsample(im_cr, 2, 2)

# Auxiliary images for displaying purposes
im_ones = np.ones((im_cb.shape[0], im_cb.shape[1]))
im_cb_rgb = ycbcr2rgb(np.dstack((im_ones*128, im_cb, im_ones*128)))
im_cr_rgb = ycbcr2rgb(np.dstack((im_ones*128, im_ones*128, im_cr)))

fig, ax = plt.subplots(1, 4, figsize=(15, 5), sharex=True, sharey=True)
ax[0].imshow(im)
ax[0].set_title('Imagen original')
ax[1].imshow(im_ybr[:,:,0], cmap='gray')
ax[1].set_title('Componente $Y$')
#ax[0].imshow(im_cb_rgb)
#ax[0].set_title('Cb component')
#ax[1].imshow(im_cr_rgb)
#ax[1].set_title('Cr component')
ax[2].imshow(im_cb, cmap='gray')
ax[2].set_title('Componente $C_B$ (escala de grises)')
ax[3].imshow(im_cr, cmap='gray')
ax[3].set_title('Componente $C_R$ (escala de grises)')

plt.savefig('plot.png', dpi=600)
plt.show()