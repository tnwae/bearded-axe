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
       ~GlobalState();

       bool hasAmbient();
       void setAmbient(bool);
       bool hasDiffuse();
       void setDiffuse(bool);
       bool hasSpecular();
       void setSpecular(bool);

       uint getShader();
       void setShader(uint);
       uint getTexture();
       void setTexture(uint);
       uint getFbo();
       void setFbo(uint);

       Vector3<float> *getCamera();
       Vector3<float> *getLight();
       void setCamera(float, float, float);
       void setLight(float, float, float);

       void setName(string);
       string toString();

       int getStateType();
       void setStateType(int);
     private:
       Vector3<float> *camera;
       Vector3<float> *light;
       bool ambient;
       bool diffuse;
       bool specular;
       uint shader;
       uint texture;
       uint fbo;
       string name;
       int stateType;
   };
}

#endif
