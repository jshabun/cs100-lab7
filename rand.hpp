#ifndef __RAND_HPP__ 
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h>

class Rand : public Base {
      protected:
	double val;
		
      public: 
	Rand() : Base () {
	srand(time(NULL));      
	val = rand() % 100 + 1;
      	}
      virtual double evaluate() { return val; }
      virtual std::string stringify() {return std::to_string(val);}
};

#endif //__RAND_HPP__
