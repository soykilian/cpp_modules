#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor called"<< std::endl;
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called"<< std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal &animal){
	*this = animal;
	std::cout << "WrongAnimal copy constructor called"<< std::endl;
}
WrongAnimal &WrongAnimal::operator=(WrongAnimal &obj){
	this->type = obj.type;
	std::cout << "WrongAnimal assignment operator"<< std::endl;
	return (*this);
}
void WrongAnimal::makeSound(void)const{
	std::cout << "*WrongAnimal sounds*"<< std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (this->type);
}

