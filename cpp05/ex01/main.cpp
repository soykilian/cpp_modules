#include "Bureaucrat.hpp"

int main(){
	Bureaucrat *b = new Bureaucrat("Mavi", 1);
	
	std::cout << b->getName() << std::endl;
	std::cout << b->getGrade() << std::endl;
	
	try{
		b->incrementGrade();
	}catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try{
		b->decrementGrade();
	}catch (std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
