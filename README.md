# About Bearded Axe

Bearded Axe is a simple generic OpenGL renderer written in clean, pure
C++.  I aim to use as few plain-C features as possible.

Features BA will have (a preliminary list):

- A clean, modular, object-oriented design amenable to my slim driver or
  another driver program
- Support for at least OFF, OBJ, and PLY mesh formats
- Support for TGA and SGI texture formats
- Support for per-object and per-scene GLSL shaders
- 100% free, open source software

Features BA might have:

- A clear, friendly scene description language
- A Lua scripting bridge ([Lua](www.lua.org) builds cleanly as standard C++.)

Bearded Axe is licensed under the GPLv3.

# Building Bearded Axe

## Prerequisites (Linux/BSD/other Unixen)

You need, at the very minimum, the proper development libraries.  These
include the development versions of `libGL`, `libGLU`, `freeglut`, and
`boost`.

I don't know what parts of Boost I'll need -- you'll hear it here
first, however, when I find out.

You also need the following utilities:

- The GNU C++ compiler, `g++`
- GNU Make
- (Someday) Automake/Autoconf

Installing the C++ compiler should give you the development libraries for
C++.  If for some reason they don't, you'll need to install them by hand.

## Prerequisites (Mac OS X)

Mac OS is the easiest platform to build on with just a few prerequisites:

- Xcode
- Boost

You can probably build on 10.4 and higher and on both PPC and Intel.
(Rock on, all six of you remaining PPC users!)  The only hard requirement
may be GCC 4.  (See [MacPorts' Trac][mptrac]
for more details on choosing a compiler for your Mac.)

[mptrac]: https://trac.macports.org/wiki/UsingTheRightCompiler

I'll add more here once I try building Bearded Axe on my MacBook.

## Prerequisites (Windows)

Likely prereqs for Windows:

- Mesa sources
- Freeglut sources
- MinGW
- Boost sources

One of the things I hope to do is build on Windows.  This will most
likely require MinGW and building Mesa and Freeglut from source, so
it'll be a bit work-intensive.  (Windows has some great OpenGL debugging
utilities, so I'm looking forward to the challenge.)

# External libraries included with Bearded Axe

To read Stanford PLY files, Bearded Axe uses the RPly library by Diego
Nehab from <http://w3.impa.br/~diego/software/ply>.

For other tasks, I have adapted examples from the OpenGL Programming
Examples site at <http://openglsamples.sf.net>.

