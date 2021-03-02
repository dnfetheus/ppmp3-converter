#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ppmp3.h"

pixel **ppmp3_create_pixels(unsigned int width, unsigned int height) {
	pixel **pixels = malloc(height * sizeof(pixel*));

	if (pixels == NULL) {
		exit(1);
	}

	for (unsigned int i = 0; i < height; i++) {
		pixels[i] = malloc(width * sizeof(pixel));

		if (pixels[i] == NULL) {
			exit(1);
		}
	}

	return pixels;
}

ppmp3_image* ppmp3_create_image(unsigned int width, unsigned int height, unsigned char max, pixel **pixels){
	ppmp3_image *image = malloc(sizeof(ppmp3_image));

	if (image == NULL) {
		exit(255);
	}

	image->height = height;
	image->width = width;
	image->max = max;
	image->pixels = pixels;

	return image;
}

void ppmp3_load_pixels(ppmp3_image *image, FILE *file) {
	for (unsigned int i = 0; i < image->height; i++) {
		for (unsigned int j = 0; j < image->width; j++) {
			fscanf(file, "%d %d %d", &image->pixels[i][j].r, &image->pixels[i][j].g, &image->pixels[i][j].b);
		}
	}
}

ppmp3_image *ppmp3_load_image(char path[]) {
	FILE *file = fopen(path, "r");

	if (file == NULL) {
		return NULL;
	}

	unsigned int width, height, max;
	char type[3];

	fscanf(file, "%s\n%d %d\n%d", &type, &width, &height, &max);

	if (strcmp(type, "P3") != 0) {
		return NULL;
	}

	pixel **pixels = ppmp3_create_pixels(width, height);
	ppmp3_image *image = ppmp3_create_image(width, height, max, pixels);

	ppmp3_load_pixels(image, file);
	fclose(file);

	return image;
}

void ppmp3_free_image(ppmp3_image *image) {
	for (unsigned int i = 0; i < image->height; i++) {
		free(image->pixels[i]);
	}

	free(image->pixels);
	free(image);
}

void ppmp3_write_image(ppmp3_image *image, char destination[]) {
	FILE *file = fopen(destination, "w");

	if(file == NULL){
		return;
	}

	fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height, image->max);

	for (unsigned int i = 0; i < image->height; i++) {
		for (unsigned int j = 0; j < image->width; j++) {
			char *template = j == image->width - 1 ? "%d %d %d\n" : "%d %d %d ";
			fprintf(file, template, image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
		}
	}
	
	fclose(file);
}

ppmp3_image *ppmp3_grayscale(ppmp3_image *image) {
	pixel **pixels = ppmp3_create_pixels(image->width, image->height);
	ppmp3_image *new_image = ppmp3_create_image(image->width, image->height, 0, pixels);
	unsigned char average_gray;

	for (unsigned int i = 0; i < new_image->height; i++) {
		for (unsigned int j = 0; j < new_image->width; j++) {
			average_gray = (int) (image->pixels[i][j].r * 0.3) + (image->pixels[i][j].g * 0.59) + (image->pixels[i][j].b * 0.11);

			if (average_gray > new_image->max) {
				new_image->max = average_gray;
			}

			new_image->pixels[i][j].r = new_image->pixels[i][j].g = new_image->pixels[i][j].b = average_gray;
		}
	}

	return new_image;
}

ppmp3_image *ppmp3_rotate(ppmp3_image *image, ppmp3_rotation mode) {
	pixel **pixels;
	ppmp3_image *new_image;

	if (mode == CLOCKWISE || mode == COUNTER_CLOCKWISE) {
		pixels = ppmp3_create_pixels(image->height, image->width);
		new_image = ppmp3_create_image(image->height, image->width, image->max, pixels);

		for (unsigned int i = 0, y; i < new_image->width; i++) {
			for (unsigned int j = 0, z; j < new_image->height; j++) {
				y = mode == CLOCKWISE ? j : new_image->height - j - 1;
				z = mode == CLOCKWISE ? new_image->width - i - 1 : i;

				new_image->pixels[y][z] = image->pixels[i][j];
			}
		}
	} else if (mode == REVERSE) {
		pixels = ppmp3_create_pixels(image->width, image->height);
		new_image = ppmp3_create_image(image->width, image->height, image->max, pixels);

		for (unsigned int i = 0; i < new_image->height; i++) {
			for (unsigned int j = 0; j < new_image->width; j++) {
				new_image->pixels[new_image->height - i - 1][new_image->width - j - 1] = image->pixels[i][j];
			}
		}
	} else {
		return NULL;
	}

	return new_image;
}

ppmp3_image *ppmp3_change_brightness(ppmp3_image *image, float percent) {
	pixel **pixels = ppmp3_create_pixels(image->width, image->height);
	ppmp3_image *new_image = ppmp3_create_image(image->width, image->height, image->max, pixels);

	float ratio = percent/100;

	for (unsigned int i = 0; i < new_image->height; i++) {
		for (unsigned int j = 0; j < new_image->width; j++) {
			new_image->pixels[i][j].r = (int) image->pixels[i][j].r * ratio;
			new_image->pixels[i][j].g = (int) image->pixels[i][j].g * ratio;
			new_image->pixels[i][j].b = (int) image->pixels[i][j].b * ratio;

			if (new_image->pixels[i][j].r > 255) new_image->pixels[i][j].r = 255;
			if (new_image->pixels[i][j].g > 255) new_image->pixels[i][j].g = 255;
			if (new_image->pixels[i][j].b > 255) new_image->pixels[i][j].b = 255;
		}
	}

	return new_image;
}
