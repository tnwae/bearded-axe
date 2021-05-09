#include <BA.hh>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <png++/png.hpp>

void error(string fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vfprintf(stderr, fmt.c_str(), ap);
}

void message(string fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vprintf(fmt.c_str(), ap);
}

namespace BA {
  extern int LogLevel;

  void DebugMessage(string fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    if(LogLevel == DEBUG_LOG) {
      vprintf(fmt.c_str(), ap);
    }
  }

  void InfoMessage(string fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    if(LogLevel >= INFO_LOG) {
      vprintf(fmt.c_str(), ap);
    }
  }

  void ConsoleMessage(string fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    if(LogLevel >= NOLOG_MSG) {
      vprintf(fmt.c_str(), ap);
    }
  }

  void renderToFile(string filename, uint x, uint y) {
    png::image<png::rgb_pixel> image(x, y);
    uchar *red = (uchar *) malloc((int)(x * y));
    uchar *green = (uchar *) malloc((int)(x * y));
    uchar *blue = (uchar *) malloc((int)(x * y));
    glReadPixels(0, 0, x, y, GL_RED, GL_UNSIGNED_BYTE, red);
    glReadPixels(0, 0, x, y, GL_GREEN, GL_UNSIGNED_BYTE, green);
    glReadPixels(0, 0, x, y, GL_BLUE, GL_UNSIGNED_BYTE, blue);

    for(uint j = 0; j < image.get_height(); j++) {
      for(uint i = 0; i < image.get_width(); i++) {
        image[y - j - 1][i] = png::rgb_pixel(red[i + j * x], green[i + j * x], blue[i + j * x]);
      }
    }

    image.write(filename);

    free(red);
    free(green);
    free(blue);

    return;
  }
}
