#include <BA/CubeObject.hh>
#include <BA/Vector3.hh>
#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    CubeObject::CubeObject(std::string _name, std::string _filename,
                               RenderType _renderType) :
    RenderObject(_name, _filename, _renderType) {
        size = (GLint) 4;
    }


    CubeObject::CubeObject(std::string _name, std::string _filename,
                               RenderType _renderType, int _size) :
    RenderObject(_name, _filename, _renderType) {
        size = (GLint) _size;
    }

    void CubeObject::render() {
        glutSolidCube((GLdouble) size);
    }
}

