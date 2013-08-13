#ifndef _BA_CUBEOBJECT_HH
#define _BA_CUBEOBJECT_HH

#include <BA.hh>
#include <BObject.hh>
#include "RenderObject.hh"
#include "Vector3.hh"

#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    class CubeObject : public RenderObject {
    public:
        CubeObject(std::string, std::string, RenderType);
        CubeObject(std::string, std::string, RenderType, int);
        void render();
    private:
        GLint size;
    };
}

#endif
