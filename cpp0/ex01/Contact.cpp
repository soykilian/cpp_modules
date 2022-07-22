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
