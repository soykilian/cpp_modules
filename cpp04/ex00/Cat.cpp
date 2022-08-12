#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat default constructor called"<< std::endl;
}
Cat::~Cat(){
	std::cout << "Cat destructor called"<< std::endl;
}
Cat::Cat(Cat &cat){
	*this = cat;
	std::cout << "Cat copy constructor called"<< std::endl;
}
Cat &Cat::operator=(Cat &obj){
	this->type = obj.type;
	std::cout << "Cat assignment operator"<< std::endl;
	return (*this);
}
void Cat::makeSound(void)const{
	std::cout << "*MEow MEow MEow*"<< std::endl;
}
