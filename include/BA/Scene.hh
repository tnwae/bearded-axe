#if ! defined _BA_SCENE_HH
#define _BA_SCENE_HH

#include <deque>
#include <vector>
#include <BObject.hh>
#include <BA/GlobalState.hh>
#include <BA/RenderObject.hh>
using namespace std;

namespace BA {
  class Scene : public BObject {
  public:
     Scene();
     ~Scene();
     void addObject(RenderObject *);
     void render();
     GlobalState *getGlobalStateById(uint);
  private:
     deque<RenderObject *> objects;
     vector<GlobalState *> globalStates;
  };
}

#endif
