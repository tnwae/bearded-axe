#ifndef _BOBJECT_HH
#define _BOBJECT_HH

#include <iostream>
#include <sstream>

class BObject {
public:
   virtual std::string toString() {
      std::stringstream ss(std::stringstream::in);
      ss << "BObject: " << this;
      return ss.str();
   }
};

#endif
