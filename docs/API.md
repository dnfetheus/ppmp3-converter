# API documentation

## Structs

### Pixel struct

```c
typedef struct pixel{
     unsigned char r;
     unsigned char g;
     unsigned char b;
} pixel;
```

#### Description
On PPM P3 files, each pixel is represented as a RGB color. So, creating a struct like that helped to work with RGB more easily.

#### Variables
* r : A char between 0 and 255 which represents a red color value;
* g : A char between 0 and 255 which represents a green color value;
* b : A char between 0 and 255 which represents a blue color value.

### PPM P3 image struct

```c
typedef struct image{
     int width;
     int height;
     unsigned char maximum;
     pixel **pixels;
} ppm_p3_image;
```

#### Description
A representation of a file which is a PPM P3. On the first line, PPM images has a type string (like "P3", but we don't use it). On the second line, the width and height are declared (like "width height"). On the next line, the maximum RGB pixel of the image is declared. And then, the pixels are there.

#### Variables

* width : A int value meaning the width of the image that is being represented;
* height : A int value meaning the height of the image that is being represented;
* maximum : A char between 0 and 255 who is representing the bigger RGB pixel of the image;
* pixels : A pointer of a pointer (it will be a heap multidimensional array) which has all pixels of the image.

---

## Functions

### Create pixels

```c
pixel** create_pixels(int width, int height)
```

#### Description

It's a function that allocs a pixel** on heap memory.

#### Parameters

* width : Width of the image;
* height : Height of the image.

#### Return

A dynamic pixel[height][width]

### Load pixels

```c
void load_pixels(ppm_p3_image *image, FILE *file)
```

#### Description
It's a function to pick each RGB pixel from PPM P3 file, and put that pixel on a relative index of ppm_p3_image.pixels[][].

#### Parameters
* image : A pointer to new allocated ppm_p3_image
* file : A pointer to the file who'll be represented by image pointer.

#### Return

Nothing.

### Create image

```c
ppm_p3_image* create_image(int width, int height, unsigned char maximum, pixel **pixels)
```

#### Description
That function receives all information of a PPM P3 file and dynamically allocs a ppm_p3_image with the information.

#### Parameters
* width : A int value meaning the width of the image that is being represented;
* height : A int value meaning the height of the image that is being represented;
* maximum : A char between 0 and 255 who is representing the bigger RGB pixel of the image;
* pixels : A pointer of a pointer (it will be a heap multidimensional array) which has all pixels of the image.

#### Return

A ppm_p3_image whose variables are equal to parameters' value.

### Load image

```c
ppm_p3_image* load_image(char name[])
```

#### Description

That function read a file based on its path. If it exists, then the function will created a ppm_p3_image based on file information.

#### Parameters

* name : The file path (like: "/home/user/Downloads/image.ppm" or "C:\Users\user\SomeFolder\image.ppm")

#### Return

NULL if the file cannot be open or if it isn't a PPM P3 file.

On the other hand, returns a ppm_p3_image whose variables are equal from the information on the file required.

### Free image

```c
void free_image(ppm_p3_image *image)
```

#### Description

Only freeing a dynamic ppm_p3_image is not enough. The pixels from ppm_p3_image are dynamic multidimensional arrays, so it must be freed too.

#### Parameters

* image : A pointer of ppm_p3_image who'll be freed.

#### Return

Nothing.

### Write image

```c
void write_image(ppm_p3_image *image, char name[])
```

#### Description

It's a function that will receive a ppm_p3_image and will write a new file on the system storage.

#### Parameters

* image : A pointer of ppm_p3_image who'll be used to create a PPM P3 file;
* name : A string representing the path and name of the new file.

#### Return

Nothing.

### Grayscale convertion

```c
ppm_p3_image* grayscale(ppm_p3_image *image)
```

#### Description

It's a approach to represent a image on grayscale schema. Transform RGB value from each pixel from image and calculate the grayscale RGB from it.

#### Parameters

* image : A pointer to ppm_p3_image that needs to be converted to grayscale.

#### Return
A ppm_p3_image based on image parameter, but on a grayscale version.

### Rotation

```c
ppm_p3_image* rotate(ppm_p3_image *image, int mode)
```

#### Description

It's a approach to rotate a image. Change each pixel from the image to another one. There are three ways to rotate the image:

1. 90º rotation (mode = 1);
2. 180º rotation (mode = 2);
3. 270º rotation (mode = 3).

#### Parameters

* image : A pointer to ppm_p3_image that needs to be rotate.

#### Return
A ppm_p3_image based on image parameter, but rotated.

### Change brightness

```c
ppm_p3_image* change_brightness(ppm_p3_image *image, float percent)
```

#### Description

It's a approach to change the brightness of a image. Each pixel will increase/decrease based on the percent parameter.

#### Parameters

* image : A pointer to ppm_p3_image that needs to has its brightness reduced/increased.;
* percent : A float value representing the percentage of brightness (like: 97,5% = 97.5 on percent parameter).

#### Return

The same ppm_p3_image from image parameter if percent is equal to 100.0.

On the other hand, returns a ppm_p3_image with the pixel changed.