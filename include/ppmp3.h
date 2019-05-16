#ifndef PPMP3_H
#define PPMP3_H

typedef struct ppmp3_image* ppmp3_image;

ppmp3_image load_image(char path[]);
void free_image(ppmp3_image image);
void write_image(ppmp3_image image, char destination[]);
ppmp3_image* grayscale(ppmp3_image image);
ppmp3_image* rotate(ppmp3_image *image, unsigned short mode);
ppmp3_image* change_brightness(ppmp3_image *image, float percent);

#endif