# libppmp3

## Description

libppmp3 is a simple C library created to read, change and save .ppm files whose type is P3.

PPM P3 files are decompressed image files, it's most used when you need to edit a image which is a decompressed one (like: JPG file -> PPM file -> new JPG file).

## API

[Here](./blob/master/API.md)

## Installation

A simple way of obtaining the library is downloading it and putting it on your project folder.

1. Clone the repository;
2. Move/copy the .c and .h files to the project folder which needs to use the library;
3. Compile your project with the libppmp3.c.

### A way to compile

```
gcc example.c example2.c ... libppmp3.c -o main
```

**Attention:** If you know another way to use the files on compilation, please change that README with the approach.

## Usage

Just include libppmp3.h on the header of the file where you'll use the library.


## Example of usage

Let's suppose that you need to load a .ppm file and create a grayscale version of it.

Here's a approach to solve the problem using libppmp3.

```c
#include "libppmp3.h"

int main(){
	ppm_p3_image *image = load_image("yee.ppm");
	ppm_p3_image *new = grayscale(image);
	write_image(new, "zee.ppm");
	return 0;
}
```

## Contributing

If you find a issue on the library, go to Issue Track and report it.

And if you want to contribute coding the library, just fork it and send a pull request when needed.


## License

>"THE BEER-WARE LICENSE" (Revision 42):
>
><fmalbernaz@protonmail.com> wrote this file. As long as you retain this notice you can do whatever you want with this stuff. If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.
>
>This project is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
>
>Felipe Matheus M.

[LICENSE](./blob/master/LICENSE.md)