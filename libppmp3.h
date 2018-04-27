#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pixel{
     int r;
     int g;
     int b;
 } pixel;

 typedef struct image{
     int width, height;
     int maximum;
     pixel **pixels;
 } ppm_p3_image;

pixel** create_pixels(int width, int height);
void load_pixels(ppm_p3_image *image, FILE *file);
ppm_p3_image* create_image(int width, int height, int maximum, pixel **pixels);
ppm_p3_image* load_image(char name[]);
void write_image(ppm_p3_image *image, char name[]);
ppm_p3_image* grayscale(ppm_p3_image *image);