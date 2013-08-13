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
  }

  void Scene::render()
  {
    for(RenderObject *ro : objects) {
      if(TeapotObject *tpt = dynamic_cast<TeapotObject *>(ro)) {
        tpt->render();
      } else if(SphereObject *s = dynamic_cast<SphereObject *>(ro)) {
        s->render();
      } else if(CubeObject *s = dynamic_cast<CubeObject *>(ro)) {
        s->render();
      } else {
        ro->render();
      }
    }
  }
}

