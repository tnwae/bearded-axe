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
   }

   std::string RenderObject::toString() {
      return name;
   }

   int RenderObject::loadGeometryFromFile(std::string where) {
      return -1;
   }

   Vector3<float> *getVertexAt(int _subscript) {
      return vertices->at(_subscript);
   }

   Vector3<float> *getFacetAt(int _subscript) {
      return facets->at(_subscript);
   }

   Vector3<float> *getSurfaceNormal(int _subscript) {
      return surfaceNormals->at(_subscript);
   }

   Vector3<float> *getVertexNormal(int _subscript) {
      return vertexNormals->at(_subscript);
   }
}
