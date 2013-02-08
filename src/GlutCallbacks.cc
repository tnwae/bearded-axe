#include <BA.hh>
#include <BA/GlutCallbacks.hh>

// extern Scene *scene;

void BA::glutCbkDisplay(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_BLEND);

  // scene->render();
  // XXX Stub render for now
  glutSolidCube(4);
  
  glutPostRedisplay();
}

void BA::glutCbkKeyboard(uchar, int, int) {

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

