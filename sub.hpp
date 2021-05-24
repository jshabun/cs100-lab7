#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <iostream>
#include <string>

#include "base.hpp"

using namespace std;

class Sub: public Base {
   public:
	Sub(Base* sub_val1, Base* sub_val2) : Base() {
		sub1 = sub_val1;
		sub2 = sub_val2;
	}
	
	virtual double evaluate() {
		return (sub1->evaluate() - sub2->evaluate());
	}

	virtual std:: string stringify() {
		return ("(" + sub1->stringify() + " - " + sub2->stringify() + ")");
	}

   private:
	Base* sub1;
	Base* sub2;
};

#endif //__SUB_HPP__
