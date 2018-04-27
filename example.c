#include "libppmp3.h"

int main(){
	ppm_p3_image *old = load_image("yee.ppm");
	write_image(old, "tee.ppm");
	return 0;
}