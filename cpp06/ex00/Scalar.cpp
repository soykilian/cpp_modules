#include "Scalar.hpp"

bool	check_printable(std::string lit){
	for (int i = 0; i < (int)lit.length(); i++)
	{
		if (std::isprint(lit[i]) == 0)
			return false;
	}
	return true;
}


void	convert(std::string literal){
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;
	std::string	types = {"-inff", "+inff", "nanf", "+inf", "-inf", "nan"};
	if (!check_printable(literal)
		return;
	if (literal.length() == 1 && std::isprint(literal) && !std::isdigit(literal))
	{
		std::cout << "char: '" + literal + "'" << std::endl;
		std::cout << "int: " << static_cast<int>literal << std::endl;
		std::cout << "float: " << static_cast<float>literal << ".0f"<<std::endl;
		std::cout << "double: " << static_cast<double>literal << ".0"<<std::endl;
		return ;
	}
	std::cout << "Keep trying"<< std::endl;
	/*
	int toInt = std::atoi(literal.c_str());
	if (literal[literal.length() - 1] == 'f')
		toFloat = std::atof(literal.c_str());
	
	*/	
}
