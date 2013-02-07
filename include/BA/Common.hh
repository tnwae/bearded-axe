#ifndef _BA_COMMON_HH
#define _BA_COMMON_HH
using namespace std;

// default width of the window
const int WIDTH = 1024;

// default height of the window
const int HEIGHT = 640;

// default title of the window
const string WINDOW_TITLE = "render";

// a few typedefs to make life easier
typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;
typedef enum _RenderType { DLIST, IMMED } RenderType;

#endif
