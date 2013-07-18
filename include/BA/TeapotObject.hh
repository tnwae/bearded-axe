#ifndef _BA_TEAPOTOBJECT_HH
#define _BA_TEAPOTOBJECT_HH

#include <BA.hh>
#include <BObject.hh>
#include "RenderObject.hh"
#include "Vector3.hh"

#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    class TeapotObject : public RenderObject {
    public:
        TeapotObject(std::string, std::string, RenderType);
        TeapotObject(std::string, std::string, RenderType, int);
        void render();
    private:
        GLint size;
    };
}

#endif
