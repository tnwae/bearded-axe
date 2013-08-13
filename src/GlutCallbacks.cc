#include <BA.hh>
#include <BA/Scene.hh>
#include <BA/GlutCallbacks.hh>
#include <cctype>

namespace BA {
  extern Scene *scene;
}

static bool wireframe_p = false;
static const float zoom_constant = 0.5;
static const float xlate_constant = 0.5;
static const float rotate_constant = 2.5;
static bool fullscreen_p = false;
static int oldheight = -1;
static int oldwidth = -1;
static int oldx = -1;
static int oldy = -1;

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
    case 'a': glRotatef( rotate_constant, 0, 1, 0); break;
    case 'd': glRotatef(-rotate_constant, 0, 1, 0); break;
    case 'w': glRotatef(-rotate_constant, 0, 0, 1); break;
    case 's': glRotatef( rotate_constant, 0, 0, 1); break;
    case 'e': glRotatef( rotate_constant, 1, 0, 0); break;
    case 'q': glRotatef(-rotate_constant, 1, 0, 0); break;
    case 'z':
      glScalef(1. + zoom_constant, 1. + zoom_constant, 1. + zoom_constant);
      break;
    case 'x':
      glScalef(1. - zoom_constant, 1. - zoom_constant, 1. - zoom_constant);
      break;
    case 'f':
      if(wireframe_p) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // filled rendering
        wireframe_p = false;
      } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // wireframe rendering
        wireframe_p = true;
      }
      message(string("%s: switching to %s mode\n"), __func__, (wireframe_p) ? "wireframe" : "solid");
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
	    } else {
	      glutPositionWindow(oldx, oldx);
	      glutReshapeWindow(oldwidth, oldheight);
	      fullscreen_p = false;
	    }
	    break;
	  case GLUT_KEY_F12:
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
  gluPerspective(75, (GLfloat) ((float) newX / (float) newY), 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

