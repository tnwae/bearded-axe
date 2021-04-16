#include <BA.hh>
#include <BA/Scene.hh>
#include <BA/GlutCallbacks.hh>
#include <cctype>

namespace BA {
  extern Scene *scene;
}

static bool wireframe_p = false;
static const float zoom_constant = 1.250000;
static const float xlate_constant = 0.500000;
static const float rotate_constant = 1.800000;
static bool fullscreen_p = false;
static const float fov = 75.;
static int oldheight = -1;
static int oldwidth = -1;
static int oldx = -1;
static int oldy = -1;

static void RotationCallback(GLfloat angle, GLfloat x, GLfloat y,
    GLfloat z) {
  char axis;

  axis = ((x == 1. && y == 0. && z == 0.) ? 'x' :
          (x == 0. && y == 1. && z == 0.) ? 'y' :
          (x == 0. && y == 0. && z == 1.) ? 'z' : '\0');

  BA::DebugMessage("%s: rotating view by %f degrees in %c-axis\n",
      __func__, angle, axis);

  glRotatef(angle, x, y, z);
}

static void ZoomCallback(GLfloat x, GLfloat y, GLfloat z) {
  BA::DebugMessage("%s: zooming %s by {%f, %f, %f}\n", __func__,
      (x < 1 ? "in" : "out"), x, y, z);
  glScalef(x, y, z);
}

void BA::glutCbkDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);

  BA::scene->render();

  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void BA::glutCbkKeyboard(uchar key, int x __attribute__((unused)), int y __attribute__((unused))) {
  switch(tolower(key))
  {
    case 'a': RotationCallback(rotate_constant, 0, 1, 0); break;
    case 'd': RotationCallback(-rotate_constant, 0, 1, 0); break;
    case 'w': RotationCallback(-rotate_constant, 0, 0, 1); break;
    case 's': RotationCallback( rotate_constant, 0, 0, 1); break;
    case 'e': RotationCallback( rotate_constant, 1, 0, 0); break;
    case 'q': RotationCallback(-rotate_constant, 1, 0, 0); break;
    case 'z':
      ZoomCallback(1. * zoom_constant, 1. * zoom_constant, 1. *
          zoom_constant); break;
      break;
    case 'x':
      ZoomCallback(1. / zoom_constant, 1. / zoom_constant, 1. /
          zoom_constant); break;
      break;
    case 'f':
      BA::DebugMessage("%s: wireframe mode ", __func__);
      if(wireframe_p) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        wireframe_p = false;
        BA::DebugMessage("off\n");
      } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        wireframe_p = true;
        BA::DebugMessage("on\n");
      }
      break;
    default:
      break;
  }
}

void BA::glutCbkSpecialKeys(int key, int x __attribute__((unused)), int y __attribute__((unused))) {
	glMatrixMode(GL_MODELVIEW);
	switch(key)
  {
	  case GLUT_KEY_F11:
	    if(!fullscreen_p) {
	      oldheight = glutGet(GLUT_WINDOW_HEIGHT);
	      oldwidth = glutGet(GLUT_WINDOW_WIDTH);
	      oldx = glutGet(GLUT_WINDOW_X);
	      oldy = glutGet(GLUT_WINDOW_Y);
	      glutFullScreen();
	      fullscreen_p = true;
        BA::DebugMessage("%s: going fullscreen\n", __func__);
	    } else {
	      glutPositionWindow(oldx, oldx);
	      glutReshapeWindow(oldwidth, oldheight);
	      fullscreen_p = false;
        BA::DebugMessage("%s: leaving fullscreen\n", __func__);
	    }
	    break;
	  case GLUT_KEY_F12:
      BA::DebugMessage("%s: leaving Bearded Axe\n", __func__);
	    exit(0); break;
	  default: break;
	}
}

void BA::glutCbkMouse(int, int, int, int) {

}

void BA::glutCbkIdle(void) {
  glutPostRedisplay();
}

void BA::glutCbkReshape(int newX, int newY) {
  glViewport(0, 0, newX, newY);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fov, (GLfloat) ((float) newX / (float) newY), 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

