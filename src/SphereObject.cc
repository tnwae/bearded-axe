#include <BA/SphereObject.hh>
#include <BA/Vector3.hh>
#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    SphereObject::SphereObject(std::string _name, std::string _filename,
                               RenderType _renderType) :
    RenderObject(_name, _filename, _renderType) {
        size = (GLint) 4;
    }


    SphereObject::SphereObject(std::string _name, std::string _filename,
                               RenderType _renderType, int _size) :
    RenderObject(_name, _filename, _renderType) {
        size = (GLint) _size;
    }

    void SphereObject::render() {
        glutSolidSphere((GLdouble) size, 16, 16);
    }
}
