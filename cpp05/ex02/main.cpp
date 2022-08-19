#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp" 

int main(){
	std::string prueba = "prueba";
	
	Bureaucrat *b = new Bureaucrat("Mavi", 20);
	Bureaucrat *a = new Bureaucrat("Pepe", 140);
	ShrubberyCreationForm	*cosas = new ShrubberyCreationForm(prueba);
	prueba = "request";
	RobotomyRequestForm	*rob = new RobotomyRequestForm(prueba);
	prueba = "pardon";
	PresidentialPardonForm	*pardon = new PresidentialPardonForm(prueba);
	std::cout << "Bureaucrat: " + b->getName() << std::endl;
	std::cout << b->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	std::cout << "Bureaucrat: " + a->getName() << std::endl;
	std::cout << a->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	
	b->signForm(*pardon);
	b->signForm(*rob);
	//b->signForm(*cosas);
	b->executeForm(*cosas);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	a->executeForm(*rob);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	b->executeForm(*pardon);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	b->executeForm(*rob);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	delete a;
	delete b;
	return (0);
}
