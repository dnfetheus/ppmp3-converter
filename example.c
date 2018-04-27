#include "libppmp3.h"

int main(){
	ppm_p3_image *old = load_image("yee.ppm");
	ppm_p3_image *new = grayscale(old);
	write_image(new, "tee.ppm");
	return 0;
}