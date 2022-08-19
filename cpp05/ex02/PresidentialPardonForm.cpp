#include "PresidentialPardonForm.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string &target): Form("Presidential", 25 , 5){
	this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj){
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj){
	Form::operator=(obj);
	return (*this);
}
std::string	PresidentialPardonForm::getTarget(void)const{
	return (this->target);
}

void PresidentialPardonForm::executeAction() const{
	std::cout << this->getTarget() + " has been pardoned by y Zafod Beeblebrox"<< std::endl;
}
