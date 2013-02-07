#if ! defined _BA_PLATFORM_HH
#define _BA_PLATFORM_HH

/*
 Fixing various platform-isms.
*/

#if defined __APPLE__  // GCC on Mac OS X
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#elif defined __linux__ // GCC on linux
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>

#elif defined _WIN32 // VisualC++ on Windows, will add support someday
#error "unsupported"

#else // other platform, e.g. Solaris, FreeBSD, Haiku
#error "unsupported"
#endif /* defined __APPLE__ */

#endif /* defined _BA_PLATFORM_HH */
