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

## Prerequisites (Linux/BSD/other Unixen)

You need, at the very minimum, the proper development libraries.  These
include the development versions of `libGL`, `libGLU`, and `freeglut`.

You also need the following utilities:

- The GNU C++ compiler, `g++`, version 4.7 for decent C++11 support.
- GNU Make (any recent version should work)
- (Someday) Automake/Autoconf

Installing the C++ compiler should give you the development libraries for
C++.  If for some reason they don't, you'll need to install them by hand.

## Prerequisites (Mac OS X)

Mac OS is the easiest platform to build on with just a few prerequisites:

- Xcode
- Boost
- GCC 4.7

GCC 4.7 is the only hard prerequisite, and according to [this Stack Overflow thread][so-gcc],
you should be able to run 4.7 on your Mac without any issues.  (Do, however, see
[MacPorts' Trac][mptrac] for more details on choosing a compiler for your Mac.)
Mac support for GCC 4.7 _may_ be Intel-only, although I doubt this matters much
anymore.

[so-gcc]: http://stackoverflow.com/questions/14534584/change-gcc-version-to-4-7-on-mac-os-x
[mptrac]: https://trac.macports.org/wiki/UsingTheRightCompiler

I no longer have a Mac suitable for testing and no particular desire to buy one.

## Prerequisites (Windows)

Likely prereqs for Windows (these are the files I have downloaded to my Windows box):

- Mesa3D 9.1.2
- Freeglut 2.8.1
- TDM-GCC 4.7.1-2 (or TDM-GCC64 4.7.1-3)
- Boost 1.53

Because Windows and OpenGL aren't the best of friends, you have to do more
work yourself.  This includes installing a suitable compiler and development
libraries.  More as it comes.

# External libraries included with Bearded Axe

To read Stanford PLY files, Bearded Axe uses the RPly library by Diego
Nehab from <http://w3.impa.br/~diego/software/ply>.

For other tasks, I have adapted examples from the OpenGL Programming
Examples site at <http://openglsamples.sf.net>.

