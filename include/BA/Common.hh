#ifndef _BA_COMMON_HH
#define _BA_COMMON_HH
#include <iostream>

namespace BA {
  // default width of the window
  const int WIDTH = 1024;

  // default height of the window
  const int HEIGHT = 768;

  // default title of the window
  const std::string WINDOW_TITLE = "Bearded Axe";

  // a few typedefs to make life easier
  typedef unsigned char uchar;
  typedef unsigned int  uint;
  typedef unsigned long ulong;
  typedef enum _RenderType { PRIM_CUBE, PRIM_SPHERE, PRIM_PYRAMID, PRIM_TEAPOT, USER_MESH } RenderType;
}

#endif

