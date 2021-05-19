#ifndef _BA_RENDEROBJECT_HH
#define _BA_RENDEROBJECT_HH

#include <BA.hh>
#include <BObject.hh>
#include "GlobalState.hh"
#include "Vector3.hh"

#include <iostream>
#include <utility>
#include <vector>

namespace BA {
  class RenderObject : public BObject {
  public:
    RenderObject(std::string, std::string, RenderType);
    virtual ~RenderObject();

    void setCenterPosition(Vector3<float> *where);
    std::string toString();
    RenderType getRenderType();

    void setAmbientVals(vector <float> *ambient);
    void setDiffuseVals(vector <float> *diffuse);
    void setSpecularVals(vector <float> *specular);
    void setShininess(float shininess);

    void render();
    virtual void renderOpCallback() = 0;

    void setRenderContext(GlobalState *);

  private:
    void preRenderCallback();
    void renderInitCallback();
    void postRenderCallback();

    bool renderTargetReached = false;

    std::string name;

    // GEOMETRY
    vector<Vector3<float> *> *vertices;
    vector<Vector3<float> *> *facets;
    vector<Vector3<float> *> *surfaceNormals;
    vector<Vector3<float> *> *vertexNormals;
    Vector3<float> *centerCoord;

    // BOUNDING BOX
    Vector3<float> minCoord;
    Vector3<float> maxCoord;
    float boundingSphereRadius;

    // TEXTURE
    uint textureHeight;
    uint textureWidth;
    GLuint textureObject;

    // LIGHT INFORMATION
    GLenum lightSource;
    float *ambientLight;
    float *diffuseLight;
    float *specularLight;
    float shininess;

    // RENDER TYPE
    RenderType renderType;

    // BOUND DISPLAY LIST
    GLuint displayList;

    // BOUND SHADER
    GLuint shaderObject;

    virtual bool loadGeometryFromFile(std::string) { return false; }
    Vector3<float> *getVertexAt(int);
    Vector3<float> *getFacetAt(int);
    Vector3<float> *getSurfaceNormalAt(int);
    Vector3<float> *getVertexNormalAt(int);

    GlobalState *renderContext;
  };
}

#endif
