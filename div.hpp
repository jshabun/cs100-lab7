#ifndef __DIV_HPP__
#define __DIV_HPP__

#include <iostream>
#include <string>

#include "base.hpp"

using namespace std;

class Div: public Base {
   public:
	Div(Base* div_val1, Base* div_val2) : Base() {
		div1 = div_val1;
		div2 = div_val2;
	}

	virtual double evaluate() {
		return (div1->evaluate() / div2->evaluate());
	}

	virtual std::string stringify() {
		return("(" + div1->stringify() + " / " + div2->stringify() + ")");
	}

   private:
	Base* div1;
	Base* div2;
};

#endif //__DIV_HPP__
