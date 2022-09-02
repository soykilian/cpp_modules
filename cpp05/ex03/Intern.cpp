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

Form *Intern::makeShrubbery(std::string target){
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobotomy(std::string target){
	return new RobotomyRequestForm(target);
}

Form *Intern::makePresidential(std::string target){
	return new PresidentialPardonForm(target);
}

Form *Intern::makeForm(std::string name, std::string target){
	std::string lower;
	int i = 0;
	static int kforms = 3;

	lower = ft_lowercase(name);
	//pointer to functions 
	t_form forms[3] = {{"shrubbery creation", &Intern::makeShrubbery},
		{"robotomy request" , &Intern::makeRobotomy},
		{"presidential pardon", &Intern::makePresidential}};
	while (i < kforms)
	{
		if (forms[i].name == lower)
		{
			std::cout << "Intern created " + name + " correclty"<<std::endl;
			return (this->*(forms[i].func))(target);
		}
		i++;
	}
	std::cout << "Intern could not find the appropiate form for " + name <<std::endl;
	return NULL;
}
