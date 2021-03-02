#ifndef PPMP3_H
#define PPMP3_H

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    unsigned short width;
    unsigned short height;
    unsigned char max;
    pixel **pixels;
} ppmp3_image;

typedef enum {
	CLOCKWISE = 1, 
	REVERSE = 2, 
	COUNTER_CLOCKWISE = 3
} ppmp3_rotation;

ppmp3_image *ppmp3_load_image(char path[]);
void ppmp3_free_image(ppmp3_image *image);
void ppmp3_write_image(ppmp3_image *image, char destination[]);
ppmp3_image *ppmp3_grayscale(ppmp3_image *image);
ppmp3_image *ppmp3_rotate(ppmp3_image *image, ppmp3_rotation mode);
ppmp3_image *ppmp3_change_brightness(ppmp3_image *image, float percent);

#endif