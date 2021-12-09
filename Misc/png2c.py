
import imageio as iio

im = iio.imread('eye_original.png')

with open("im_rgb.h",'wb') as result_file:
  result_file.write(b'const unsigned char %s PROGMEM = {' % f'im_rgb[{im.shape[0]}][{im.shape[1]}][{im.shape[2]}]'.encode('utf-8'))

  for row in im:
    result_file.write(b'{')

    for pixel in row:
      result_file.write(b'{%s},' % f'{str(pixel[0])}, {str(pixel[1])}, {str(pixel[2])}'.encode('utf-8'))
    
    result_file.write(b'},')


  result_file.write(b'};\nunsigned int im_width = %s;\n' % str(im.shape[1]).encode('utf-8'))
  result_file.write(b'unsigned int im_height = %s;' % str(im.shape[0]).encode('utf-8'))
