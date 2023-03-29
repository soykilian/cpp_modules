#ifndef RPN_HPP
# define RPN_HPP
#include <fstream>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
class RPN{
	private:
		char *str;
		std::stack<float> stack;
	public:
		RPN();
		~RPN();
		RPN(char *arg);
		RPN(const std::string &filename);
		RPN(const RPN &obj);
		RPN &operator=(RPN &obj);
		void operate(char op);
		void compute();
};
#endif
