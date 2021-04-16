#include <BA.hh>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

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
}
