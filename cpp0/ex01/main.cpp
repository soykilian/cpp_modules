#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	std::string		cmd;
	PhoneBook	agenda;

	while (std::cout << "Type CMD : ", std::getline(std::cin, cmd))
	{
		if(cmd == "ADD")
			agenda.ft_new_contact();
		else if(cmd == "SEARCH")
			agenda.ft_list_contacts();
		else if (cmd == "EXIT")
			break;
	}
}
