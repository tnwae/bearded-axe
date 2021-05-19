#include <BA/Scene.hh>
#include <BA/GlobalState.hh>
#include <BA/RenderObject.hh>
#include <BA/TeapotObject.hh>
#include <BA/SphereObject.hh>
#include <BA/CubeObject.hh>
#include <BA/Vector3.hh>
#include <iostream>
#include <utility>
#include <vector>

namespace BA {
  Scene::Scene()
  {
    GlobalState *tex = new GlobalState();

    tex->setAmbient(true);
    tex->setDiffuse(true);
    tex->setSpecular(true);
    tex->setName("state0");
    tex->setTexture((uint) 0);
    tex->setStateType(BA::GS_TEXTURE);
    tex->setLight(8, 8, 0);
    tex->setCamera(8, 8, 8);

    globalStates.push_back(tex);
  }

  Scene::~Scene() {
    for(RenderObject *ro : objects) {
      delete ro;
    }
  }

  void Scene::addObject(RenderObject *ro)
  {
    objects.push_back(ro);
    DebugMessage("Added object %s to scene\n", ro->toString().c_str());
  }

  /**
   * Render the scene.
   */
  void Scene::render()
  {
    for(GlobalState *gs : globalStates) {
      Vector3<float> *light = gs->getLight();
      GLfloat pos[] = {light->x, light->y, light->z, 0};
      glLightfv(GL_LIGHT0, GL_POSITION, pos);
      for(RenderObject *ro : objects) {
        ro->setRenderContext(gs);
        ro->render();
      }
    }
  }
}

