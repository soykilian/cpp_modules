#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Form.hpp" 
#include "Intern.hpp" 

int main(){
	Bureaucrat *b = new Bureaucrat("Mavi", 20);
	Bureaucrat *a = new Bureaucrat("Pepe", 120);
	Intern *c = new Intern();
		
	Form *rob = c->makeForm("robotomy request", "oda");
	Form *pardon = c->makeForm("presidential pardon", "prueba");
	Form	*shrubbery = c->makeForm("shrubbery creation", "murder");
	Form	*prueba = c->makeForm("jorge creation", "jorge");
	if (prueba == NULL)
		prueba ++;
	std::cout << "Bureaucrat: " + b->getName() << std::endl;
	std::cout << b->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	std::cout << "Bureaucrat: " + a->getName() << std::endl;
	std::cout << a->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	
	b->signForm(*pardon);
	b->signForm(*rob);
	//b->signForm(*cosas);
	b->executeForm(*shrubbery);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	a->executeForm(*rob);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	b->executeForm(*pardon);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	b->executeForm(*rob);
	std::cout << "-------------------------------------------------------------------------------------------------------"<< std::endl;
	delete a;
	delete b;
	delete c;
	return (0);
}
