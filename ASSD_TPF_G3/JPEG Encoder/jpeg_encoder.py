import imageio as iio
import numpy as np
from ycbcr import *
from subsampling import subsample, upsample
from dct_tables import *
from dct_quantization import *
from huffman_encoding import huffman_encoding
from jfif_bin import jfif_bin

def jpeg_encode(input_path, output_path, quality = 50):
    # Open original image
    im = iio.imread(input_path)

    # Convert RGB data to the YCbCr color space
    print('RGB to YCBCR')
    im_ybr = rgb2ycbcr(im)

    # Perform chroma subsampling 4:2:0 (2x2)
    print('Subsampling')
    ss_factor = 2 # subsampling factor
    im_y = subsample(im_ybr[:, :, 0], 1, 1).astype(np.uint8)
    im_cb = subsample(im_ybr[:, :, 1], ss_factor, ss_factor).astype(np.uint8)
    im_cr = subsample(im_ybr[:, :, 2], ss_factor, ss_factor).astype(np.uint8)

    # Perform DCT and Quantization
    print('DCT')
    dqt_luma_table = DQT_LUMA_100 if quality == 100 else DQT_LUMA_50
    dqt_chroma_table = DQT_CHROMA_100 if quality == 100 else DQT_CHROMA_50
    im_dqt_y = dct_quantization(im_y, dqt_luma_table, 8)
    im_dqt_cb = dct_quantization(im_cb, dqt_chroma_table, 8)
    im_dqt_cr = dct_quantization(im_cr, dqt_chroma_table, 8)

    # Perfom Huffman encoding
    print('Huffman')
    im_huff = huffman_encoding(im_dqt_y, im_dqt_cb, im_dqt_cr, subsampling=ss_factor)
    
    # Generate binary JPEG file
    print('Binary file')
    binary_file = jfif_bin(im_huff, *np.shape(im_dqt_y), dqt_luma_table, dqt_chroma_table, (ss_factor,ss_factor))

    with open(output_path, 'wb') as fo:
        binary_file.tofile(fo)

    print('Done!')

## Test code

jpeg_encode('chelsea.png', 'chelsea.jpg')