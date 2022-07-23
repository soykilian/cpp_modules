#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setContact(std::string FirstName, std::string LastName,
		std::string nickname, std::string phoneNumber, std::string darkSecret)
{
	this->first_name = FirstName;
	this->last_name = LastName;
	this->nickname = nickname;
	this->phone_number = phoneNumber;
	this->darkest_secret = darkSecret;
}

std::string setString(std::string str)
{
	if (str.length() > 10)
		return(str.substr(0,9) + ".");
	return str;
}

void Contact::printTable(int i)
{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << setString(this->first_name);
		std::cout << "|" << std::setw(10) << setString(this->last_name);
		std::cout << "|" << std::setw(10) << setString(this->nickname) << "|\n";
}
void Contact::printContact()
{
	std::cout << "First Name : " << this->first_name << std::endl;
	std::cout << "Last Name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
}
