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
  Scene::Scene(GlobalState *gs)
  {
    globalStates.push_back(gs);
  }

  void Scene::addObject(RenderObject *ro)
  {
    objects.push_back(ro);
    DebugMessage("Added object %s to scene\n", ro->toString().c_str());
  }

  void Scene::render()
  {
    for(RenderObject *ro : objects) {
      ro->render();
    }
  }
}

