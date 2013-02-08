#include <BA.hh>
#include <BA/GlutCallbacks.hh>
#include <iostream>

int main(int argc, char *argv[]) {
  float position[4] = { 0, 80, 0, 1. };
  float specular[4] = { 0.774597, 0.774597, 0.774597, 1. };
  float diffuse[4] = { 0.4, 0.4, 0.4, 1. };
  float ambient[4] = { 0.25, 0.25, 0.25, 1. };
  float shininess[1] = { 76.8 };
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(WINDOW_TITLE.c_str());
  glutReshapeWindow(WIDTH, HEIGHT);

  // a little OGL init work...
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glClearColor(0., 0., 0., 1.0);
  glClearDepth(1.0);
  glShadeModel(GL_SMOOTH);
  glPolygonMode(GL_FRONT, GL_FILL);
  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0., 8., 8.,
            0., 0., 0.,
            0., 1., 0.);

  glutDisplayFunc(BA::glutCbkDisplay);
  glutReshapeFunc(BA::glutCbkReshape);
  //glutKeyboardFunc(BA::glutCbkKeyboard);
  glutKeyboardFunc(NULL);
  //glutSpecialFunc(BA::glutCbkSpecialKeys);
  glutSpecialFunc(NULL);
  //glutMouseFunc(BA::glutCbkMouse);
  glutMouseFunc(NULL);
  glutIdleFunc(BA::glutCbkIdle);

  std::cout << __func__ << ": This is Bearded Axe (git-20130208)" << std::endl;
  std::cout << __func__ << ": Let's get started..." << std::endl;

  glutMainLoop();
}
