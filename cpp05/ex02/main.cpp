#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

int main(){
	std::string prueba = "prueba";
	Bureaucrat *b = new Bureaucrat("Mavi", 1);
	Bureaucrat *a = new Bureaucrat("Pepe", 140);
	ShrubberyCreationForm	*cosas = new ShrubberyCreationForm(prueba);
	Form	*uno = new Form("Covid Test", 130, 130);
	std::cout << "Bureaucrat: " + b->getName() << std::endl;
	std::cout << b->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	std::cout << "Bureaucrat: " + a->getName() << std::endl;
	std::cout << a->getGrade() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	std::cout << "Current form: "+ uno->getName() << std::endl;
	std::cout << uno->getGradeToSign() << std::endl;
	std::cout << "---------------------------------------"<< std::endl;
	
	std::cout << cosas->getGradeToSign() << std::endl;
	std::cout << cosas->getGradeToExec() << std::endl;
	b->signForm(*uno);
	a->signForm(*uno);
	try{
		cosas->execute(*a);
	}catch(std::exception &e){
		std::cout << a->getName() << " tried to sign " << cosas->getName() << " but threw an exception: " << e.what() << std::endl;
	}
	cosas->execute(*b);

}
