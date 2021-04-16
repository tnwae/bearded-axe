# About Bearded Axe

Bearded Axe is a simple generic OpenGL renderer written in clean, pure C++.  The Axe would be a serviceable foundation for e.g. a video game engine.

Anticipated features:

- Clean, modular, object-oriented design amenable to most driver programs
- Support for OFF, OBJ, and COLLADA meshes
- Support for PNG, JPG, SGI, and TGA textures
- Support for per-object and per-scene shaders
- Copyleft licensing under GPL3
- A stupid name

Roadmap features:

- Scene description language (probably XML or JSON)
- Lua scripting bridge

# Building Bearded Axe

Bearded Axe is only tested on the Linux family of operating systems.

## Prerequisites (Linux/BSD/other Unixen)

You need, at the very minimum, the proper development libraries.  These include the development versions of `libGL`, `libGLU`, and `freeglut`.  There may be subtle differences between Linux and other Unixen, and I neither know nor care about the specifics.  For me, it's not a real computer unless it runs Debian Linux, and that is where I do the bulk of my testing.

I use GNU Make though other `make`s should work, and the use of GNU C++ is universal.

## Prerequisites (macOS)

Sell your Mac and buy a real computer, install Linux or BSD on that real computer, then see above.

## Prerequisites (Windows)

Delete Windows off your computer and install Linux or BSD, then see above.

# External libraries included with Bearded Axe

To read Stanford PLY files, Bearded Axe uses the RPly library by Diego Nehab from <http://w3.impa.br/~diego/software/ply>.

For other tasks, I have adapted examples from the OpenGL Programming Examples site at <http://openglsamples.sf.net>.

