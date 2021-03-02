#include <stdio.h>
#include "../include/ppmp3.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments");
    }

    ppmp3_image *image = ppmp3_load_image(argv[1]);

    ppmp3_image *grayscale_image = ppmp3_grayscale(image);
    ppmp3_free_image(image);

    ppmp3_image *darkened_image = ppmp3_change_brightness(grayscale_image, 50.0);
    ppmp3_free_image(grayscale_image);

    ppmp3_image *inverted_image = ppmp3_rotate(darkened_image, CLOCKWISE);
    ppmp3_free_image(darkened_image);
    
    ppmp3_write_image(inverted_image, argv[2]);
    ppmp3_free_image(inverted_image);

    return 0;
}