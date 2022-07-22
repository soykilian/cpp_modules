#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook () {this->number_contacts=0;}
PhoneBook::~PhoneBook () {}

void PhoneBook::ft_new_contact()
{
	std::string components[5];
	std::string names[5] = {"First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret"};
	for (int i = 0; i<5 ; i++)
	{
		while (components[i].empty())
		{
			std::cout<< "Enter " + names[i] + ":" ;
			std::getline(std::cin, components[i]);
		}
	}
	Contact tmp = Contact();
	tmp.setContact(components[0], components[1], components[2], components[3], components[4]);
	this->contact_book[this->number_contacts % MAX_CONTACT] = tmp;
	this->number_contacts += 1;
}

void PhoneBook::ft_list_contacts()
{
	std::string tmp;
	int idx;
	int i = 0;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|\n";
	if (this->number_contacts == 0)
		return;
	while (i < this->number_contacts && i < MAX_CONTACT)
	{
		this->contact_book[i].printTable(i);
		i++;
	}
	std::cout << "Enter index : ";
	std::getline(std::cin, tmp);
	if (tmp.empty() || !std::isdigit(tmp[0]) || tmp.length() != 1)
		return;
	std::istringstream(tmp) >> idx;
	if (idx > this->number_contacts - 1)
		return;
	this->contact_book[idx].printContact();
}

