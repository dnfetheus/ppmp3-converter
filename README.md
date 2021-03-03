# PPMP3 Manipulation

Just a bunch of functions to deal with PPMP3 images.

## Getting Started

As wrote before, the core of this repository is made of functions to deal with PPMP3 images. You can use them as you want to.

But if you want to test, the next steps will give you instructions to.

### Prerequisites

**make** is needed to use [Makefile](Makefile).

You can use any **C compiler** you want. 

### Installing

[main.c](src/main.c) contains a functional usage code for example. Just use [Makefile](Makefile) to build a executable.
```sh
make
```
**P.S.:** Makefile is configured to use GCC as compiler. If you want to change it, just assign **CC** in Makefile to your compiler of choice.

### Using

The example takes as an input a path to an existing PPMP3 image and as an output generates a PPMP3 image to a chosen path.
```sh
./ppmp3 in.ppm out.ppm
```

## License

This repository is licensed under the MIT License.

Read [LICENSE](LICENSE) to see more details.
