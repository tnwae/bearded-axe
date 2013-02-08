#ifndef _BA_VECTOR_3_HH
#define _BA_VECTOR_3_HH
#include <sstream>
#include <cmath>

namespace BA {
   template <typename T> class Vector3 {
   public:
      Vector3<T>() {
	 x = (T) 0;
	 y = (T) 0;
	 z = (T) 0;
      }

      ~Vector3<T>() {

      }

      Vector3<T>(T _x, T _y, T _z) {
	 x = _x;
	 y = _y;
	 z = _z;
      }

      T getX() { return x; }
      T getY() { return y; }
      T getZ() { return z; }

      Vector3<T> &operator=(const Vector3<T> &rhs) {
	 if(this != &rhs) {
	    rhs.x = x;
	    rhs.y = y;
	    rhs.z = z;
	 }

	 return *this;
      }

      Vector3<T> &operator+=(const Vector3<T> &rhs) {
	 if(this != &rhs) {
	    x += rhs.x;
	    y += rhs.y;
	    z += rhs.z;
	 }

	 return *this;
      }

      Vector3<T> &operator-=(const Vector3<T> &rhs) {
	 if(this != &rhs) {
	    x -= rhs.x;
	    y -= rhs.y;
	    z -= rhs.z;
	 }

	 return *this;
      }

      Vector3<T> &operator*=(const T &rhs) {
	 x *= rhs;
	 y *= rhs;
	 z *= rhs;

	 return *this;
      }

      Vector3<T> &operator*=(const Vector3<T> &rhs) {
	 Vector3<T> crossprod;
	 
	 if(this != &rhs) {
	    crossprod.x = y * rhs.z - z * rhs.y;
	    crossprod.y = z * rhs.x - x * rhs.z;
	    crossprod.z = x * rhs.y - y * rhs.x;
	 }

	 return crossprod;
      }

      Vector3<T> &operator+(const Vector3<T> &rhs) {
	 return Vector3(*this) += rhs;
      }

      Vector3<T> &operator-(const Vector3<T> &rhs) {
	 return Vector3(*this) -= rhs;
      }

      Vector3<T> &operator*(const T &rhs) {
	 return Vector3(*this) *= rhs;
      }

      Vector3<T> &operator*(const Vector3<T> &rhs) {
	 return Vector3(*this) *= rhs;
      }

      bool operator==(const Vector3<T> &rhs) {
	 return x == rhs.x && y == rhs.y && z == rhs.z;
      }

      /*
	Note this uses standard floating point math for now.
       */
      T norm() {
	 T result = (T) 0;
	 result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	 return result;
      }

      T dot(Vector3<T> &other) {
	 T dprod = (T) 0;
	 dprod += x * other.x;
	 dprod += y * other.y;
	 dprod += z * other.z;
	 return dprod;
      }

      Vector3<T> &normalize() {
	 Vector3<T> retval(0, 0, 0);
	 T normal = norm();
	 retval.x = x / normal;
	 retval.y = y / normal;
	 retval.z = z / normal;
	 return retval;
      }

      std::string toString() {
	 std::stringstream ss(std::stringstream::in);
	 ss << "(" << x << ", " << y << ", " << z << ")";
	 return ss.str();
      }

      T x, y, z;
   };
}

#endif
