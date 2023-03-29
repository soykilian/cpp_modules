#include "RPN.hpp" 
RPN::RPN(){
}

RPN::~RPN(){
}

RPN::RPN(char* arg): str(arg){
	compute();
}

RPN::RPN(const RPN &obj){
	this->stack = obj.stack;
}

RPN &RPN::operator=(RPN &obj){
	if (this != &obj)
		this->stack = obj.stack;
	return (*this);
}
void RPN::operate(char op){
	float op1;
	float op2;
	if (stack.size() < 2)
		return;
	op1 = stack.top();
	stack.pop();
	op2 = stack.top();
	stack.pop();
	switch(op)
	{
	case '/':
		if (op1 == '0')
		{
			std::cout << "Cannot perform division by zero" << std::endl;
			break;
		}
		stack.push(op2/op1);
		break;
	case '*':
		stack.push(op2*op1);
		break;
	case '-':
		stack.push(op2-op1);
		break;
	case '+':
		stack.push(op2+op1);
		break;
	}
}
void RPN::compute()
{
	bool space = false;
	std::string ops = "/+-*";
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			stack.push(str[i] - '0');
			space = false;
		}
		else if (ops.find(str[i]) != std::string::npos)
		{
			operate(str[i]);
			space = false;
		}
		else if (str[i] == ' ')
		{
			if (space == true)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			space = true;
		}
		else 
		{
			std::cout << "Error" << std::endl;
			return;
		} 
		i++;
	}
	std::cout << stack.top() << std::endl;
}
