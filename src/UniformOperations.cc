#include <BA.hh>
#include <BA/Vector3.hh>
#include <BA/Uniforms.hh>
#include <vector>
#include <iostream>

namespace BA {
  static GLint getUniformLocation(unsigned shader, std::string which) {
    return getUniformLocation(shader, which.c_str());
  }

  int setUniform(unsigned shad, std::string which, bool value)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform1f(uniform_location, value);
    return uniform_location;  
  }


  int setUniform(unsigned shad, std::string which, float value)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform1f(uniform_location, value);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, float x, float y)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform2f(uniform_location, x, y);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, float x, float y, float z)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform3f(uniform_location, x, y, z);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, float x, float y, float z, float w) 
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform4f(uniform_location, x, y, z, w);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, int value)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform1i(uniform_location, value);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, int x, int y)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform2i(uniform_location, x, y);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, int x, int y, int z)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform3i(uniform_location, x, y, z);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, int x, int y, int z, int w) 
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform4i(uniform_location, x, y, z, w);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, unsigned value)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform1ui(uniform_location, value);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform2ui(uniform_location, x, y);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y, unsigned z)
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform3ui(uniform_location, x, y, z);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y, unsigned z, unsigned w) 
  {
    GLint uniform_location = getUniformLocation(shad, which);
    if(uniform_location != -1) glUniform4ui(uniform_location, x, y, z, w);
    return uniform_location;  
  }

  int setUniform(unsigned shad, std::string which, std::vector<float> array)
  {
    switch(array.size()) {
      case 1: return setUniform(shad, which, array[0]);
      case 2: return setUniform(shad, which, array[0], array[1]);
      case 3: return setUniform(shad, which, array[0], array[1], array[2]);
      case 4: return setUniform(shad, which, array[0], array[1], array[2], array[3]);
      default: return -1;
    }
  }

  int setUniform(unsigned shad, std::string which, std::vector<int> array)
  {
    switch(array.size()) {
      case 1: return setUniform(shad, which, array[0]);
      case 2: return setUniform(shad, which, array[0], array[1]);
      case 3: return setUniform(shad, which, array[0], array[1], array[2]);
      case 4: return setUniform(shad, which, array[0], array[1], array[2], array[3]);
      default: return -1;
    }
  }

  int setUniform(unsigned shad, std::string which, std::vector<unsigned> array)
  {
    switch(array.size()) {
      case 1: return setUniform(shad, which, array[0]);
      case 2: return setUniform(shad, which, array[0], array[1]);
      case 3: return setUniform(shad, which, array[0], array[1], array[2]);
      case 4: return setUniform(shad, which, array[0], array[1], array[2], array[3]);
      default: return -1;
    }
  }

  int setUniform(unsigned shad, std::string which, Vector3<int> value) {
    return setUniform(shad, which, value.x, value.y, value.z);
  }

  int setUniform(unsigned shad, std::string which, Vector3<float> value) {
    return setUniform(shad, which, value.x, value.y, value.z);
  }

  int setUniform(unsigned shad, std::string which, Vector3<unsigned> value) {
    return setUniform(shad, which, value.x, value.y, value.z);
  }
}
