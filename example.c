#include "libppmp3.h"

int main(){
	ppm_p3_image *image = load_image("yee.ppm");
	ppm_p3_image *new = change_gamma(image, 80.0);
	ppm_p3_image *new2 = rotate(image, 2);
	ppm_p3_image *new3 = grayscale(new2);
	write_image(new, "tee.ppm");
	write_image(new2, "xee.ppm");
	write_image(new3, "zee.ppm");
	return 0;
}
