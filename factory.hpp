#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

class Factory {
	public:
		Factory(){};
		virtual ~Factory(){};
		virtual Base* parse(char** input, int len) = 0;

};

#endif //__FACTORY_HPP__
