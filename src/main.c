#include <stdio.h>
#include "../include/ppmp3.h"

int main(){
    ppmp3_image image = ppmp3_load_image("/path/to/ppmfile");

    image = ppmp3_grayscale(image);
    image = ppmp3_change_brightness(image, 50.0);
    image = ppmp3_rotate(image, CLOCKWISE);
    
    ppmp3_write_image(image, "/path/to/destination");
    ppmp3_free_image(image);

    return 0;
}