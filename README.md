# PPM P3 Manipulation

Just a bunch of functions to deal with PPM P3 images. You can use them as you want to.

If you want to test, the next steps will give you instructions to.
## Installation

**make** is needed to use [Makefile](Makefile).

You can use any **C compiler** you want. 

[main.c](src/main.c) contains a functional usage code for example. Just use [Makefile](Makefile) to build a executable.
```sh
make
```
**P.S.:** Makefile is configured to use GCC as compiler. If you want to change it, just assign **CC** in Makefile to your compiler of choice.

## Usage

The example takes as an input a path to an existing PPMP3 image and as an output generates a PPMP3 image to a chosen path.
```sh
./ppmp3 in.ppm out.ppm
```

## License

[MIT](LICENSE)
