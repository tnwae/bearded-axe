#include <BA.hh>
#include <BA/Vector3.hh>
#include <BA/GlobalState.hh>
#include <BA/Scene.hh>
#include <BA/GlutCallbacks.hh>
#include <BA/RenderObject.hh>
#include <BA/TeapotObject.hh>
#include <BA/CubeObject.hh>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

namespace BA {
  Scene *scene;
  int LogLevel = NOLOG_MSG;
}

int main(int argc, char *argv[]) {

  /*
    GLUT initialization preamble.
   */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow(BA::WINDOW_TITLE.c_str());
  glutReshapeWindow(BA::WIDTH, BA::HEIGHT);

  int opt;

  while((opt = getopt(argc, argv, "ldq")) != -1) {
    switch(opt) {
      case 'l':
        BA::LogLevel = BA::INFO_LOG;
        break;
      case 'd':
        BA::LogLevel = BA::DEBUG_LOG;
        break;
      case 'q':
        BA::LogLevel = BA::SILENT_LOG;
        break;
      default:
        std::cerr << "usage: " << argv[0] << " [-(l|d|q)]" << std::endl;
        exit(EXIT_FAILURE);
    }
  }

  /*
    Initialize the working state for OpenGL

    TODO: Adjust to use shaders rather than fixed pipeline
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glClearColor(0., 0., 0., 1.0);  // black background
  glClearDepth(1.0);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_MODELVIEW);
  glPolygonMode(GL_FRONT, GL_FILL);
  glLoadIdentity();
  gluLookAt(8., 8., 8.,
            0., 0., 0.,
            0., 1., 0.);

  BA::scene = new BA::Scene();

  BA::TeapotObject *tpt = new BA::TeapotObject(std::string("teapot0"),
      std::string(""), BA::PRIM_TEAPOT, 4);
  tpt->setCenterPosition(new BA::Vector3<float>(0, 2, 0));
  tpt->setSpecularVals(new vector<float>({ 1., 1., 1., 1. }));
  tpt->setDiffuseVals(new vector<float>({ 1., 0., 0., 1. }));
  tpt->setAmbientVals(new vector<float>({ 1., 0., 0., 1. }));
  tpt->setShininess(95.0);
  BA::scene->addObject(tpt);

  BA::CubeObject *cube = new BA::CubeObject(std::string("cube0"),
      std::string(""), BA::PRIM_CUBE, 18);
  cube->setCenterPosition(new BA::Vector3<float>(0, -10, 0));
  cube->setSpecularVals(new vector<float>({ 1., 1., 1., 1. }));
  cube->setDiffuseVals(new vector<float>({ 0., 0., 1., 1. }));
  cube->setAmbientVals(new vector<float>({ 0., 0., 1., 1. }));
  cube->setShininess(40.0);
  BA::scene->addObject(cube);

  glutDisplayFunc(BA::glutCbkDisplay);
  glutReshapeFunc(BA::glutCbkReshape);
  glutKeyboardFunc(BA::glutCbkKeyboard);
  glutSpecialFunc(BA::glutCbkSpecialKeys);
  //glutMouseFunc(BA::glutCbkMouse);
  glutMouseFunc(NULL);
  glutIdleFunc(BA::glutCbkIdle);

  BA::ConsoleMessage("%s: Welcome to Bearded Axe (git-20210513)\n", __func__);
  BA::ConsoleMessage("%s: [f2] to dump buffer to png\n", __func__);
  BA::ConsoleMessage("%s: [f11] to go fullscreen\n", __func__);
  BA::ConsoleMessage("%s: [f12] to quit\n", __func__);

  glutMainLoop();

  exit(EXIT_SUCCESS);
}

