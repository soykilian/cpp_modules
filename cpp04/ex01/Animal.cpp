#include "Animal.hpp"

Animal::Animal() : type("Animal"){
	std::cout << "Animal default constructor called"<< std::endl;
}
Animal::~Animal(){
	std::cout << "Animal destructor called"<< std::endl;
}
Animal::Animal(const Animal &animal){
	*this = animal;
	std::cout << "Animal copy constructor called"<< std::endl;
}
Animal &Animal::operator=(const Animal &obj){
	this->type = obj.type;
	std::cout << "Animal assignment operator"<< std::endl;
	return (*this);
}
void Animal::makeSound(void)const{
	std::cout << "*Animal sounds*"<< std::endl;
}

std::string Animal::getType(void) const{
	return (this->type);
}

