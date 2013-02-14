#include <BA/Vector3.hh>
using namespace BA;

#include <iostream>
#include <cassert>
#include <cmath>
#include <cfloat>
#include <memory>
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
   unique_ptr<float[]> aa = va.toArray();
   Vector3<float> vj(aa.get());

// KNOWN VALUES.
// I found these either by hand or with the help of Wolfram Alpha.
   float dot = 10;
   float norm = 40;
   Vector3<float> scale(2, 4, 6);
   Vector3<float> cprod(-4, 8, -4);
   Vector3<float> sum(4, 4, 4);
   Vector3<float> diff(0, 0, 0);

// test 1: dot product value is correct
   assert(ve == dot);
   cout << "test 1 passed (dot product)" << endl;

// test 2: sum is correct
   assert(vc == sum);
   cout << "test 2 passed (sum)" << endl;

// test 3: norm is correct
   assert(vg == norm);
   cout << "test 3 passed (norm)" << endl;

// test 4: cross product is correct
   assert(cprod == vf);
   cout << "test 4 passed (cross product)" << endl;

// test 5: scale vector by single number amount is correct
   assert(scale == vd);
   cout << "test 5 passed (scalar)" << endl;

// test 6: difference is correct
   assert(diff == vh);
   cout << "test 6 passed (difference)" << endl;

// norm of a normalized vector = 1
   assert(fabs(vi.norm()) - 1 < FLT_EPSILON);
   cout << "test 7 passed (norm of normalized = 1)" << endl;

// print format is correct
   assert(vh.toString().compare("(0, 0, 0)") == 0);
   cout << "test 8 passed (print format correct)" << endl;

// conversion to array succeeds
   assert(va.toArray() != NULL);
   cout << "test 9 passed (conversion to array successful)" << endl;

// converted array contains the same values as the original
   assert(aa[0] == va.x);
   assert(aa[1] == va.y);
   assert(aa[2] == va.z);
   cout << "test 10 passed (converted array and original are equal)" << endl;

// vector created from array is created correctly
   assert(vj.x == aa[0]);
   assert(vj.y == aa[1]);
   assert(vj.z == aa[2]);
   cout << "test 11 passed (vector created from array has correct values)" << endl;
}
