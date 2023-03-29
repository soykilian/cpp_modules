#include "BitcoinExchange.hpp"
#include <iostream>
int main(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		std::cout << "Error in file" << std::endl;
		return (1);
	}
	BitcoinExchange obj(argv[1]);
	return (0);
}

