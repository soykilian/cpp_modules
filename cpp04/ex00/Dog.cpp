#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << "Dog default constructor called"<< std::endl;
}
Dog::~Dog(){
	std::cout << "Dog destructor called"<< std::endl;
}
Dog::Dog(Dog &dog){
	*this = dog;
	std::cout << "Dog copy constructor called"<< std::endl;
}
Dog &Dog::operator=(Dog &obj){
	this->type = obj.type;
	std::cout << "Dog assignment operator"<< std::endl;
	return (*this);
}
void Dog::makeSound(void)const{
	std::cout << "Woof Woof!!!"<< std::endl;
}
