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

    void RenderObject::render() {
        return;
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
    }

    std::string RenderObject::toString() {
        return name;
    }
}
