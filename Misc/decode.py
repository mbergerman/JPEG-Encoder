from dqt import *

def decode_jpeg(im_jpeg, table=DQT_LUMA_50, block_size=8):
    im_out = np.zeros((im_jpeg.shape[0], im_jpeg.shape[1]), np.uint8)

    for y in range(0, len(im_jpeg), block_size):
        for x in range(0, len(im_jpeg[0]), block_size):
            block_dct = im_jpeg[y:y+block_size, x:x+block_size] * table
            block_idct = idct(block_dct)
            im_out[y:y+block_size, x:x+block_size] = np.clip(block_idct + 128, 0, 255)

    return im_out