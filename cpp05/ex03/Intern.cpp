#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


Intern::Intern(){
	std::cout << "Intern created" << std::endl;
}
Intern::~Intern(){ 
	std::cout << "Intern destroyed" << std::endl;
}
Intern::Intern(Intern const &obj){
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj){
	if (this == &obj)
		return (*this);
	return (*this);
}


static std::string	ft_lowercase(std::string str)
{
	std::string		lower(str);

	for (int i = 0; i < (int)lower.length(); i++)
	{
		if(std::islower(lower[i])){
			lower[i] = std::tolower(lower[i]);
		}
	}
	return lower;
}

Form *Intern::makeForm(std::string name, std::string target){
	std::string lower;
	int i = 0;
	Form *obj = NULL;
	static int kforms = 3;

	lower = ft_lowercase(name);
	t_form forms[3] = {{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request" , new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}};
	while (i < kforms)
	{
		if (forms[i].name == lower)
		{
			obj = forms[i].form;
			break;
		}
		i++;
	}
	if (obj == NULL)
		std::cout << "Intern could not find the appropiate form for " + name <<std::endl;
	std::cout << "Intern created " + name + " correclty"<<std::endl;
	return obj;
}
