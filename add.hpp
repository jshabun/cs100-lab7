#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <iostream>
#include <string>

#include "base.hpp"

using namespace std;

class Add: public Base {
   public:
	Add(Base* add_val1, Base* add_val2) : Base() {
		 add1 = add_val1;
	  	 add2 = add_val2;
	}

	virtual double evaluate() {
		 return (add1->evaluate() + add2->evaluate());
	}

	virtual std::string stringify() {
		 return ("(" + add1->stringify() + " + " + add2->stringify() + ")");
	}

   private:
	Base* add1;
	Base* add2;
};

#endif //__ADD_HPP__
