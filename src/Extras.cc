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
