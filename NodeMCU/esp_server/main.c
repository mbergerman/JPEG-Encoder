#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "im_rgb.h"

unsigned char*** rgb2ycbcr(const unsigned char*** im_rgb, unsigned int width, unsigned int height);

int main()
{

    printf("%d", im_rgb[0][0][0]);

    // Convert RGB data to the YCbCr color space
    unsigned char*** im_ybr = rgb2ycbcr((const unsigned char***) im_rgb, im_width, im_height);

    /*
    # Perform chroma subsampling 4:2:0 (2x2)
    print('Subsampling')
    s = 2 #subsampling en chroma
    im_y = subsample(im_ybr[:, :, 0], 1, 1).astype(np.uint8)
    im_cb = subsample(im_ybr[:, :, 1], s, s).astype(np.uint8)
    im_cr = subsample(im_ybr[:, :, 2], s, s).astype(np.uint8)

    # Perform DCT and Quantization
    print('DCT')
    im_dqt_y = dct_dqt(im_y, DQT_LUMA_100, 8)
    im_dqt_cb = dct_dqt(im_cb, DQT_CHROMA_100, 8)
    im_dqt_cr = dct_dqt(im_cr, DQT_CHROMA_100, 8)

    #Perfom Huffman encoding
    # v_huff_y = huffman_encoding(im_dqt_y)
    # v_huff_cb = huffman_encoding(im_dqt_cb)
    # v_huff_cr = huffman_encoding(im_dqt_cr)
    print('Huffman')
    v_huff = huffman_encoding(im_dqt_y,im_dqt_cb,im_dqt_cr,subsampling=s)
    print('Binary')
    binary_file = jfif(v_huff, *np.shape(im_dqt_y), DQT_LUMA_100, DQT_CHROMA_100, (s,s))

    with open(f'{file_name}.jpg', 'wb') as fo:
        binary_file.tofile(fo)
*/
}


unsigned char*** rgb2ycbcr(const unsigned char*** im_rgb, unsigned int width, unsigned int height){
    printf("hola");
    unsigned char *** im_ybr = (unsigned char ***)malloc(height * width * 3 * sizeof(unsigned char));
    printf("hola");
    for(unsigned int y = 0; y < height; y++){
        for(unsigned int x = 0; x < width; x++){
            printf("%d, %d", x, y);
            im_ybr[y][x][0] = 0   + 0.299 * (float)im_rgb[y][x][0] + 0.587 * (float)im_rgb[y][x][1] + 0.114 * (float)im_rgb[y][x][2];
            im_ybr[y][x][1] = 128 - 0.168736 * (float)im_rgb[y][x][0] - 0.331264 * (float)im_rgb[y][x][1] + 0.5 * (float)im_rgb[y][x][2];
            im_ybr[y][x][2] = 128 + 0.5 * (float)im_rgb[y][x][0] - 0.418688 *(float)im_rgb[y][x][1] - 0.081312 * (float)im_rgb[y][x][2];
        }
    }
    return im_ybr;
}