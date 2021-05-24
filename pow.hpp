#ifndef __POW_HPP__
#define __POW_HPP__

#include <iostream>
#include <string>
#include <cmath>

#include "base.hpp"

using namespace std;

class Pow: public Base {
   public:
	Pow(Base* num_base, Base* num_exp) : Base() {
		base_val = num_base;
		exp_val = num_exp;
	}
	
	virtual double evaluate() {
		return (pow(base_val->evaluate(), exp_val->evaluate()));
	}
	
	virtual std::string stringify() {
		return ("(" + base_val->stringify() + " ** " + exp_val->stringify() + ")" );
	}
	
   private:
	Base* base_val;
	Base* exp_val;
};

#endif //__POW_HPP__
