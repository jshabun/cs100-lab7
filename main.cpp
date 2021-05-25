#include<iostream>

#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include "parse.hpp"
#include "factory.hpp"

using namespace std;

int main(int argc, char** argv) {
	Factory* factory_pattern = new Parse();
	Base* test = factory_pattern -> parse(argv, argc);
	
	if (test) {
		cout << test -> stringify() << " = " << test -> evaluate() << endl;
	} else {
		cout << "Invalid" << endl;
	}

	delete factory_pattern;
	delete test;
		
	return 0;
}
