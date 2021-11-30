import numpy as np

def rgb2ycbcr(im_rgb):
    im_ybr = np.zeros_like(im_rgb, dtype=np.uint8)
    for y, row in enumerate(im_rgb):
        for x, pixel in enumerate(row):
            im_ybr[y][x][0] = 0   + 0.299    * pixel[0] + 0.587    * pixel[1] + 0.114    * pixel[2]
            im_ybr[y][x][1] = 128 - 0.168736 * pixel[0] - 0.331264 * pixel[1] + 0.5      * pixel[2]
            im_ybr[y][x][2] = 128 + 0.5      * pixel[0] - 0.418688 * pixel[1] - 0.081312 * pixel[2]
    return im_ybr

def ycbcr2rgb(im_ybr):
    im_rgb = np.zeros_like(im_ybr, dtype=np.uint8)
    for y, row in enumerate(im_ybr):
        for x, pixel in enumerate(row):
            im_rgb[y][x][0] = pixel[0] + 0        * (pixel[1] - 128) + 1.402    * (pixel[2] - 128)
            im_rgb[y][x][1] = pixel[0] - 0.344136 * (pixel[1] - 128) - 0.714136 * (pixel[2] - 128)
            im_rgb[y][x][2] = pixel[0] + 1.772    * (pixel[1] - 128) + 0        * (pixel[2] - 128)
    return im_rgb
