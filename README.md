# About Bearded Axe

Bearded Axe is a simple generic OpenGL renderer written in clean, pure
C++.  I aim to use as few plain-C features as possible.

Features BA will have (a preliminary list):

- A clean, modular, object-oriented design amenable to my slim driver or
  another driver program
- Support for at least OFF, OBJ, and PLY mesh formats
- Support for at least PNG, TGA, and SGI texture formats
- Support for per-object and per-scene GLSL shaders
- 100% free, open source software

Features BA might have:

- A clear, friendly scene description language
- A Lua scripting bridge ([Lua](www.lua.org) builds cleanly as standard C++.)

Bearded Axe is licensed under the GPLv3.

# Building Bearded Axe

## Prerequisites (Linux)

You need, at the very minimum, the proper development libraries.  These
include the development versions of `libGL`, `libGLU`, and `freeglut`.
The manner in which you get these will differe based on your distro.

You also need the following utilities:

- The GNU C++ compiler, `g++`, at minimum version 4.7 for decent C++11 support.
- GNU Make (any recent version should work)

Installing the C++ compiler should give you the development libraries for
C++.  If for some reason they don't, you'll need to install them by hand.

## Prerequisites (macOS)

0. Download Parallels Desktop or UTM.
1. Install Linux.
2. Follow the Linux instructions above.

## Prerequisites (Windows)

0. Format your hard drive.
1. Install Linux.
2. Follow the Linux instructions above.

# External libraries included with Bearded Axe

To read Stanford PLY files, Bearded Axe uses the RPly library by Diego
Nehab from <http://w3.impa.br/~diego/software/ply>.

For other tasks, I have adapted examples from the OpenGL Programming
Examples site at <http://openglsamples.sf.net>.

