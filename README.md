# Bearded Axe

A couple years ago, my last college project was to write an OpenGL rendering
program in C.  While it worked out great (although the renders didn't look
so good since I suck at shader programming), I've decided to comb through
the old code and write a C++ version that incorporates code by other people.
In particular, I hope to add support for several mesh formats and to write
a better scene description language.

# Building Bearded Axe

## Prerequisites

You need, at the very minimum, the proper development libraries.  On
Fedora 18 (and probably earlier versions), these are:

- `mesa-libGL-devel`
- `mesa-libGLU-devel`
- `freeglut-devel`
- `boost-devel` (NOTE: I haven't used any Boost packages yet, so I'm not
  certain what I'll need or what version.)

TODO: Add Debian/Ubuntu/Mint build deps here

You also need the following utilities:

- The GNU C++ compiler, g++ (package `g++` in Debian/Ubuntu, `gcc-c++`
  in Fedora)
- GNU Make

## Libraries

To read Stanford PLY files, Bearded Axe uses the RPly library by Diego
Nehab from <http://w3.impa.br/~diego/software/ply>.

For other tasks, I have adapted examples from the OpenGL Programming
Examples site at <http://openglsamples.sf.net>.

