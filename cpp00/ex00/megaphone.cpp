#include <iostream>
#include <cstdlib>

static std::string	ft_uppercase(std::string str)
{
	std::string		upper(str);

	for (int i = 0; i < (int)upper.length(); i++)
	{
		if(std::islower(upper[i])){
			upper[i] = std::toupper(upper[i]);
		}
	}
	return upper;
}
int main(int argc, char *argv[])
{
	if (argc==1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
	}
	else
	{
		for (int i = 1; i<argc; i++)
		{
			std::cout << ft_uppercase(argv[i]);
		}
		std::cout << std::endl;
	}
}
