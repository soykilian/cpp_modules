#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook () {}
PhoneBook::~PhoneBook () {}

void PhoneBook::ft_new_contact()
{
	std::string components[5];
	std::string names[5] = {"First Name:", "Last Name:", "Nickname", "Phone Number", "Darkest Secret"};
	for (int i = 0; i<5 ; i++)
	{
		while (components[i].empty())
		{
			std::cout<< "Enter " + names[i] + ":" + components[i] + ":";
		}
	}
}

