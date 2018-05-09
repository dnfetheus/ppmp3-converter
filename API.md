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
A representation of a file which is a PPM P3. On the first line, PPM images has a type string (like "P3", but we don't use it). On the second line, the width and height are declared (like "$(width) $(height)"). On the next line, the maximum RGB pixel of the image is declared. And then, the pixels are there.

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
void load_pixels(ppm_p3_image *image, FILE *file);
```

#### Description
It's a function to pick each RGB pixel from PPM P3 file, and put that pixel on a relative index of ppm_p3_image.pixels[][].

#### Parameters
* image : A pointer to new allocated ppm_p3_image;
* file : A pointer to the file who'll be represented by image pointer.

