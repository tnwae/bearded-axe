#include <BA.hh>
#include <BA/Scene.hh>
#include <BA/GlutCallbacks.hh>
#include <cctype>

namespace BA {
  extern Scene *scene;
}

void BA::glutCbkDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);

  BA::scene->render();
  
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void BA::glutCbkKeyboard(uchar key, int x, int y) {
  switch(std::tolower(key)) {
    case 'q':
	  exit(0);
  }
}

void BA::glutCbkSpecialKeys(int, int, int) {

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

