#include <stdlib.h>

typedef struct pixel{
     unsigned char r;
     unsigned char g;
     unsigned char b;
 } pixel;

 typedef struct image{
     int width, height;
     int maximum;
     pixel **pixels;
 } ppm_p3_image;

pixel** create_pixels(int width, int height);