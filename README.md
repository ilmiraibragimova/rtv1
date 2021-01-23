# rtv1
RTv1 is a simple ray tracer. It parses a 3D scene from a file and applies ray tracing algorithm to render the given scene.
Note: this project was made for MacOS.

Installation:
Clone or download this repository and run make in command line while in the root of the repository. This will build executable called RTv1. Makefile compiles SDL2 library from source files (as stated in the subject, see rtv1.en.pdf) so building process might take some time.

Usage
./RTv1 [filename]
filename must contain path to a valid scene.
If the scene is not valid, RTv1 will write corresponding error on standard output.

![](https://github.com/ilmiraibragimova/rtv1/raw/master/image/image1.png)

Inside the sphere, that crossed another sphere

![inside the sphere, that crossed another sphere](https://github.com/ilmiraibragimova/rtv1/raw/master/image/image2.png)

![](https://github.com/ilmiraibragimova/rtv1/raw/master/image/image3.png)


