#include "libppmp3.h"

int main(){
	ppm_p3_image *image = load_image("yee.ppm");
	grayscale(image);
	write_image(image, "tee.ppm");
	return 0;
}
