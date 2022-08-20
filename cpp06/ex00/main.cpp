#include <iostream>

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
	bool		impossible = false;
	int 	i = 0;
	std::string	toChar = "";
	std::string	types[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	if (!check_printable(literal))
		return;
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		std::cout << "char: '" << std::string(literal)[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f"<<std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0"<<std::endl;
		return;
	}
	while (i < 6)
	{
		if (literal ==types[i])
		{
			impossible = true;
			break;
		}
		i++;
	}
	if (impossible == true)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << types[i%3] << std::endl;
		std::cout << "double: " << types[i%3 + 3] << std::endl;
		return ;
	}
	toInt = std::atoi(literal.c_str());
	if (std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (!std::isprint(toInt))
		toChar = "Non displayable";
	if (literal[literal.length() - 1] == 'f')
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}
	std::cout << "char: " << toChar << std::endl;
	std::cout << "int: " << toInt << std::endl;
	if (toFloat - static_cast<int>(toFloat) == 0)
	{
		std::cout << "float: " << toFloat << ".0f" << std::endl;
		std::cout << "double: " << toDouble << ".0" << std::endl;
	}
	else 
	{
		std::cout << "float: " << toFloat << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of args"<< std::endl;
		return (1);
	}
	convert(std::string(argv[1]));
	return (0);
}
