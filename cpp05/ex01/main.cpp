#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat *b = new Bureaucrat("Mavi", 1);
	Bureaucrat *a = new Bureaucrat("Pepe", 140);
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
	
	b->signForm(*uno);
	a->signForm(*uno);
}
