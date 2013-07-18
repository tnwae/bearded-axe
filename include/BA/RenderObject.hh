#ifndef _BA_RENDEROBJECT_HH
#define _BA_RENDEROBJECT_HH

#include <BA.hh>
#include <BObject.hh>
#include "Vector3.hh"

#include <iostream>
#include <utility>
#include <vector>

namespace BA {
  class RenderObject : public BObject {
  public:
    RenderObject(std::string, std::string, RenderType);
    ~RenderObject();

    std::string toString();

    void render();
  private:
    std::string name;

    // GEOMETRY
    vector<Vector3<float> *> *vertices;
    vector<Vector3<float> *> *facets;
    vector<Vector3<float> *> *surfaceNormals;
    vector<Vector3<float> *> *vertexNormals;

    // BOUNDING BOX
    Vector3<float> minCoord;
    Vector3<float> maxCoord;
    float boundingSphereRadius;

    // TEXTURE
    uint textureHeight;
    uint textureWidth;
    GLuint textureObject;

    // LIGHT INFORMATION
    float ambientLight[4];
    float diffuseLight[4];
    float specularLight[4];
    float shininess;

    // RENDER TYPE
    RenderType renderType;

    // BOUND DISPLAY LIST
    GLuint displayList;

    // BOUND SHADER
    GLuint shaderObject;

    int loadGeometryFromFile(std::string);
    Vector3<float> *getVertexAt(int);
    Vector3<float> *getFacetAt(int);
    Vector3<float> *getSurfaceNormalAt(int);
    Vector3<float> *getVertexNormalAt(int);
  };
}

#endif
