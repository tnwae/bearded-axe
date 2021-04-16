#ifndef _BA_SPHEREOBJECT_HH
#define _BA_SPHEREOBJECT_HH

#include <BA.hh>
#include <BObject.hh>
#include "RenderObject.hh"
#include "Vector3.hh"

#include <iostream>
#include <utility>
#include <vector>

namespace BA {
    class SphereObject : public RenderObject {
    public:
        SphereObject(std::string, std::string, RenderType);
        SphereObject(std::string, std::string, RenderType, int);
    protected:
        void renderOpCallback();
    private:
        GLint size;
    };
}

#endif
