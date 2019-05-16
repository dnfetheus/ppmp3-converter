#ifndef PPMP3_H
#define PPMP3_H

typedef struct ppmp3_image* ppmp3_image;
typedef enum ppmp3_rotation ppmp3_rotation;

ppmp3_image ppm3_load_image(char path[]);
void ppmp3_free_image(ppmp3_image image);
void ppmp3_write_image(ppmp3_image image, char destination[]);
ppmp3_image ppmp3_grayscale(ppmp3_image image);
ppmp3_image ppmp3_rotate(ppmp3_image image, ppmp3_rotation mode);
ppmp3_image ppmp3_change_brightness(ppmp3_image image, float percent);

#endif