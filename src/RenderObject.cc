#include <BA/RenderObject.hh>
#include <BA/Vector3.hh>
#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    RenderObject::RenderObject(std::string _name, std::string _filename, RenderType _renderType) {
        name = _name;
        renderType = _renderType;

        vertices = new std::vector<Vector3<float> *>;
        facets = new std::vector<Vector3<float> *>;
        surfaceNormals = new std::vector<Vector3<float> *>;
        vertexNormals = new std::vector<Vector3<float> *>;

        loadGeometryFromFile(_filename);
    }

    /**
     * Render the object.  This callback is called once each frame.
     */
    void RenderObject::render() {
      if(!renderTargetReached) {
        DebugMessage("%s: render target reached for %s\n", __func__,
            this->toString().c_str());
        renderTargetReached = true;
      }
      RenderObject::preRenderCallback();
      RenderObject::renderInitCallback();
      renderOpCallback();
      RenderObject::postRenderCallback();
    }

    void RenderObject::preRenderCallback() {
      glPushMatrix();
    }

    void RenderObject::renderInitCallback() {
      glPolygonMode(GL_FRONT, GL_FILL);
      glLightfv(this->lightSource, GL_POSITION,
          this->centerCoord->toArray().get());
      glLightfv(this->lightSource, GL_DIFFUSE, this->diffuseLight);
      glLightfv(this->lightSource, GL_SPECULAR, this->specularLight);
      glLightfv(this->lightSource, GL_AMBIENT, this->ambientLight);
      glMaterialfv(GL_FRONT, GL_SHININESS, &(this->shininess));
      glTranslatef(this->centerCoord->x, this->centerCoord->y,
          this->centerCoord->z);

      return;
    }

    void RenderObject::renderOpCallback() { }

    void RenderObject::postRenderCallback() {
      glPopMatrix();
    }

    void RenderObject::setAmbientVals(std::vector<float> *ambient) {
      ambientLight = ambient->data();
    }

    void RenderObject::setDiffuseVals(std::vector<float> *diffuse) {
      diffuseLight = diffuse->data();
    }

    void RenderObject::setSpecularVals(std::vector<float> *specular) {
      specularLight = specular->data();
    }

    void RenderObject::setShininess(float shininess) {
      this->shininess = shininess;
    }

    void RenderObject::setCenterPosition(Vector3<float> *where) {
        centerCoord = where;
    }

    RenderType RenderObject::getRenderType() {
        return renderType;
    }

    RenderObject::~RenderObject() {
        std::vector<Vector3<float>*>::iterator vit;

        for(vit = vertices->begin(); vit != vertices->end(); vit++) {
            delete *vit;
        }

        delete vertices;

        for(vit = facets->begin(); vit != facets->end(); vit++) {
            delete *vit;
        }

        delete facets;

        for(vit = surfaceNormals->begin(); vit != surfaceNormals->end(); vit++) {
            delete *vit;
        }

        delete surfaceNormals;

        for(vit = vertexNormals->begin(); vit != vertexNormals->end(); vit++) {
            delete *vit;
        }

        delete vertexNormals;
        delete centerCoord;
        delete ambientLight;
        delete diffuseLight;
        delete specularLight;
    }

    std::string RenderObject::toString() {
        return name;
    }
}
