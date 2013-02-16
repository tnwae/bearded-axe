#ifndef _BA_UNIFORMS_HH
#define _BA_UNIFORMS_HH

#include <iostream>
#include <vector>
#include "Vector3.hh"

namespace BA {
  int setUniform(unsigned shad, std::string which, std::vector<float> array);
  int setUniform(unsigned shad, std::string which, std::vector<int> array);
  int setUniform(unsigned shad, std::string which, std::vector<unsigned> array);
  int setUniform(unsigned shad, std::string which, Vector3<int> array);
  int setUniform(unsigned shad, std::string which, Vector3<float> array);
  int setUniform(unsigned shad, std::string which, Vector3<unsigned> array);
  int setUniform(unsigned shad, std::string which, bool value);
  int setUniform(unsigned shad, std::string which, float value);
  int setUniform(unsigned shad, std::string which, int value);
  int setUniform(unsigned shad, std::string which, float x, float y);
  int setUniform(unsigned shad, std::string which, float x, float y, float z);
  int setUniform(unsigned shad, std::string which, float x, float y, float z, float w) ;
  int setUniform(unsigned shad, std::string which, int x, int y);
  int setUniform(unsigned shad, std::string which, int x, int y, int z);
  int setUniform(unsigned shad, std::string which, int x, int y, int z, int w) ;
  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y);
  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y, unsigned z);
  int setUniform(unsigned shad, std::string which, unsigned x, unsigned y, unsigned z, unsigned w) ;
}

#endif
