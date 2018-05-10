#include "../headers/libppmp3.h"

pixel** create_pixels(int width, int height){
	pixel **new = (pixel**) malloc(height * sizeof(pixel*));
	if (new == NULL){
		printf("Error on memory allocation\n");
		exit(255);
	}
	int i;
	for (i = 0; i < height; i++){
		new[i] = (pixel*) malloc(width * sizeof(pixel));
		if (new[i] == NULL){
			printf("Error on memory allocation\n");
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

ppm_p3_image* create_image(int width, int height, unsigned char maximum, pixel **pixels){
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
		return NULL;
	}
	int w, h, max;
	char type[3];
	fscanf(file, "%s\n%d %d\n%d", &type, &w, &h, &max);
	if (strcmp(type, "P3") != 0){
		printf("The file isn't a PPM P3 image\n");
		return NULL;
	}
	pixel **pixels = create_pixels(w, h);
	ppm_p3_image *image = create_image(w, h, max, pixels);
	load_pixels(image, file);
	fclose(file);
	return image;
}

void free_image(ppm_p3_image *image){
	int i;
	for (i = 0; i < image->height; i++){
		free(image->pixels[i]);
	}
	free(image->pixels);
	free(image);
}

void write_image(ppm_p3_image *image, char name[]){
	FILE *file = fopen(name, "w");
	if (file == NULL){
		printf("File cannot be saved\n");
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
	free_image(image);
	fclose(file);
}

ppm_p3_image* grayscale(ppm_p3_image *image){
	int i, j;
	ppm_p3_image *new = create_image(image->width, image->height, 0, create_pixels(image->width, image->height));
	for (i = 0; i < new->height; i++){
		for (j = 0; j < new->width; j++){
			unsigned char average_gray = (int) (image->pixels[i][j].r * 0.3) + (image->pixels[i][j].g * 0.59) + (image->pixels[i][j].b * 0.11);
			new->pixels[i][j].r = average_gray;
			new->pixels[i][j].g = average_gray;
			new->pixels[i][j].b = average_gray;
			if (average_gray > new->maximum)
				new->maximum = average_gray;
		}
	}
	return new;
}

ppm_p3_image* rotate(ppm_p3_image *image, int mode){
	ppm_p3_image *new;
	pixel **pixels;
	int i, j, width, height;
	switch(mode){
		case 1:
			width = image->height;
			height = image->width;
			pixels = create_pixels(width, height);
			for (i = 0; i < width; i++){
				for (j = 0; j < height; j++){
					pixels[j][width - i - 1] = image->pixels[i][j];
				}
			}
			break;
		case 2:
			width = image->width;
			height = image->height;
			pixels = create_pixels(width, height);
			for (i = 0; i < height; i++){
				for (j = 0; j < width; j++){
					pixels[height - i - 1][width - j - 1] = image->pixels[i][j];
				}
			}
			break;
		case 3:
			width = image->height;
			height = image->width;
			pixels = create_pixels(width, height);
			for (i = 0; i < width; i++){
				for (j = 0; j < height; j++){
					pixels[height - j - 1][i] = image->pixels[i][j];
				}
			}
			break;
		default:
			return NULL;
	}
	new = create_image(width, height, image->maximum, pixels);
	return new;
}

ppm_p3_image* change_brightness(ppm_p3_image *image, float percent){
	if(percent == 100.0)
		return image;
	float realpercent = percent/100;
	int i, j;
	ppm_p3_image *new;
	pixel **pixels = create_pixels(image->width, image->height);
	for (i = 0; i < image->height; i++){
		for (j = 0; j < image->width; j++){
			pixels[i][j].r = (int) image->pixels[i][j].r * realpercent <= 255 ? image->pixels[i][j].r * realpercent : 255;
			pixels[i][j].g = (int) image->pixels[i][j].g * realpercent <= 255 ? image->pixels[i][j].g * realpercent : 255;
			pixels[i][j].b = (int) image->pixels[i][j].b * realpercent <= 255 ? image->pixels[i][j].b * realpercent : 255;
		}
	}
	new = create_image(image->width, image->height, image->maximum, pixels);
	return new;
}
