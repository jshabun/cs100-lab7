#ifndef __PARSE_HPP__
#define __PARSE_HPP__

#include<iostream>
#include<queue>
#include<stack>
#include<string>

#include "factory.hpp"

using namespace std;

class Parse : public Factory {
	public:
		Base* parse(char** input, int len) {
			queue<Base*> numbers;
			stack<char*> operators;

			for (int i = 1; i < len; i++) {
				string var = input[i];
			
				if ((var == "+") || (var == "*") || (var == "-") || (var == "/") || (var == "**")) {
					operators.push(input[i]);
				} else {
					Base* op = new Op(atof(input[i]));
					numbers.push(op);
				}

				if (numbers.size() == 2) {
					string var2 = operators.top();
					
					if (var2 == "+") {
						Base* add = new Add(numbers.front(), numbers.back());
						for (int j = 1; j < 3; j++) {
							numbers.pop();
						}
						operators.pop();
						numbers.push(add);

					} else if (var2 == "*") {
						Base* mult = new Mult(numbers.front(), numbers.back());
                        for (int j = 1; j < 3; j++) {
                            numbers.pop();
                        }
                        operators.pop();
                        numbers.push(mult);

					} else if (var2 == "-") {
						Base* sub = new Sub(numbers.front(), numbers.back());
                        for (int j = 1; j < 3; j++) {
                            numbers.pop();
                        }
                        operators.pop();
                        numbers.push(sub);

					} else if (var2 == "/") {
						Base* div = new Div(numbers.front(), numbers.back());
                        for (int j = 1; j < 3; j++) {
                            numbers.pop();
                        }
                        operators.pop();
                        numbers.push(div);

					} else if (var2 == "**") {
						Base* pow = new Pow(numbers.front(), numbers.back());
                        for (int j = 1; j < 3; j++) {
                            numbers.pop();
                        }
                        operators.pop();
                        numbers.push(pow);
					}
				}
			}
			
			if (!operators.empty()) {
				if (!numbers.empty()) {
					delete numbers.front();
				}
				
				return nullptr;
			}

			return numbers.front();
		}		
};

#endif //__PARSE_HPP__
