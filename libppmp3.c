#include "libppmp3.h"

pixel** create_pixels(int width, int height){
	pixel** new = (pixel**) malloc(height * sizeof(pixel*));
	if (new == NULL){
		printf("Error on memory allocation\n");
		exit(255);
	}
	int i;
	for (i = 0; i < height; i++){
		new[i] = (pixel*) malloc(width * sizeof(pixel));
		if (new[i] == NULL){
			printf("Error on memory allocation");
			exit(255);
		}
	}
	return new;
}

void load_pixels(ppm_p3_image *image, FILE *file){
	int i, j;
	for (i = 0; i < image->height; i++){
		for (j = 0; j < image->width; j++){
			fscanf(file, "%d %d %d", &image->pixels[i][j].r, &image->pixels[i][j].g, &image->pixels[i][j].b);
		}
	}
}

ppm_p3_image* create_image(int width, int height, int maximum, pixel **pixels){
	ppm_p3_image *image = (ppm_p3_image*) malloc(sizeof(ppm_p3_image));
	if (image == NULL){
		printf("Error on memory allocation");
		exit(255);
	}
	image->height = height;
	image->width = width;
	image->maximum = maximum;
	image->pixels = pixels;
	return image;
}

ppm_p3_image* load_image(char name[]){
	FILE *file = fopen(name, "r");
	if (file == NULL){
		printf("Cannot be able to open the file\n");
		exit(127);
	}
	int w, h, max;
	char type[2];
	fscanf(file, "%s\n%d %d\n%d", &type, &w, &h, &max);
	if (strcmp(type, "P3") != 0){
		printf("%s\n", type);
		printf("The file isn't a PPM P3 image\n");
		exit(128);
	}
	pixel **pixels = create_pixels(w, h);
	ppm_p3_image *image = create_image(w, h, max, pixels);
	load_pixels(image, file);
	fclose(file);
	return image;
}

void write_image(ppm_p3_image *image, char name[]){
	FILE *file = fopen(name, "w");
	if (file == NULL){
		printf("File wasn't able to be opened\n");
		exit(127);
	}
	fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height, image->maximum);
	int i, j;
	for (i = 0; i < image->height; i++){
		for(j = 0; j < image->width; j++){
			if (j == image->width - 1)
				fprintf(file, "%d %d %d\n", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
			else
				fprintf(file, "%d %d %d ", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
		}
	}
	fclose(file);
}

void free_image(ppm_p3_image *image){
	int i;
	for (i = 0; i < image->height; i++){
		free(image->pixels[i]);
	}
	free(image);
}

ppm_p3_image* grayscale(ppm_p3_image *image){
	ppm_p3_image *new = create_image(image->width, image->height, image->maximum, image->pixels);
	int i, j;
	for (i = 0; i < new->height; i++){
		for (j = 0; j < new->width; j++){
			int average_gray = (int) (new->pixels[i][j].r * 0.3) + (new->pixels[i][j].g * 0.59) + (new->pixels[i][j].b * 0.11);
			new->pixels[i][j].r = average_gray;
			new->pixels[i][j].g = new->pixels[i][j].r;
			new->pixels[i][j].b = new->pixels[i][j].r;
			if(new->pixels[i][j].r > new->maximum)
				new->maximum = new->pixels[i][j].r;
		}
	}
	return new;
}