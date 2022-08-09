#include "Karen.hpp"

Karen::Karen(){}
Karen::~Karen(){}
static std::string	ft_tolower(std::string str)
{
	std::string		lower(str);

	for (int i = 0; i < (int)lower.length(); i++)
	{
		if(std::isupper(lower[i])){
			lower[i] = std::tolower(lower[i]);
		}
	}
	return lower;
}
void Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	int	pos = 10;
	std::string levels[] = {"debug", "info", "warning", "error"};
	std::string l = ft_tolower(level);
	void (Karen::*f[])() = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	for (int i=0; i < 4; i++)
	{
		if (levels[i].compare(l) == 0)
			pos = i;
	}
	switch(pos)
	{
		case 0:
			(this->*f[0])();
		case 1 :
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
