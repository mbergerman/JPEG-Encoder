import numpy as np

def rgb2ycbcr(im_rgb):
    coeffs = np.array([[.299, .587, .114], [-.168736, -.331264, .5], [.5, -.418688, -.081312]])
    im_ybr = im_rgb.dot(coeffs.T)
    im_ybr[:,:,[1,2]] += 128
    return np.uint8(im_ybr)

def ycbcr2rgb(im_ybr):
    coeffs = np.array([[1, 0, 1.402], [1, -0.344136, -.714136], [1, 1.772, 0]])
    im_rgb = im_ybr.astype(np.float64)
    im_rgb[:,:,[1,2]] -= 128
    im_rgb = im_rgb.dot(coeffs.T)
    np.clip(im_rgb, 0, 255)
    return np.uint8(im_rgb)