
#include <iostream>
#include <string>

int main(void)
{
	std::string		cmd;

	while (std::cout << "Type CMD : ", std::getline(std::cin, cmd))
	{
		if(cmd == "ADD")
			break;
	}
}
