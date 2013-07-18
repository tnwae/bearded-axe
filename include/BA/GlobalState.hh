
#ifndef _BA_GLOBALSTATE_HH
#define _BA_GLOBALSTATE_HH
#include <vector>
using namespace std;

#include <BObject.hh>
#include <BA/Vector3.hh>

namespace BA {
   const int GS_TEXTURE  = 0;
   const int GS_SHADOW   = 1;
   const int GS_SPECULAR = 7;

   class GlobalState : public BObject {
     public:
       GlobalState();
     private:

   };
}

#endif
