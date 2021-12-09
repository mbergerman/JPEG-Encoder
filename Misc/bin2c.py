import sys

original_file = "chelsea_eye.jpg"

with open("c_array.h",'wb') as result_file:
  result_file.write(b'const char %s[] = {' % "jpeg_bin".encode('utf-8'))

  nbytes = 0
  for b in open(original_file, 'rb').read():
    result_file.write(b'0x%02X,' % b)
    nbytes += 1
  result_file.write(b'}    // Len = %s' % str(nbytes).encode('utf-8'))