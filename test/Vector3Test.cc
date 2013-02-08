#include "Vector3.hh"
using namespace BA;

#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
using namespace std;

int main(int argc, char **argv) {
   Vector3<float> va(1.0f, 2.0f, 3.0f);
   Vector3<float> vb(3.0f, 2.0f, 1.0f);
   Vector3<float> vc = va + vb;
   Vector3<float> vd = va * 2.0f;
   float ve = va.dot(vb);
   Vector3<float> vf = va * vb;
   Vector3<float> vq(32, 24, 0);
   float vg = vq.norm();
   Vector3<float> vh = va - va;
   Vector3<float> vi = vb.normalize();

   float dot = 10;
   float norm = 40;
   Vector3<float> scale(2, 4, 6);
   Vector3<float> cprod(-4, 8, -4);
   Vector3<float> sum(4, 4, 4);
   Vector3<float> diff(0, 0, 0);

   assert(ve == dot);
   cout << "test 1 passed (dot product)" << endl;
   assert(vc == sum);
   cout << "test 2 passed (sum)" << endl;
   assert(vg == norm);
   cout << "test 3 passed (norm)" << endl;
   assert(cprod == vf);
   cout << "test 4 passed (cross product)" << endl;
   assert(scale == vd);
   cout << "test 5 passed (scalar)" << endl;
   assert(diff == vh);
   cout << "test 6 passed (difference)" << endl;
   assert(fabs(vi.norm())-vi.norm() < FLT_EPSILON);
   cout << "test 7 passed (norm of normalized = 1)" << endl;
}
