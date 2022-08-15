#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called"<< std::endl;
}
Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called"<< std::endl;
}
Dog::Dog(const Dog &dog): Animal(dog){
	std::cout << "TRAZA"<< std::endl;
	this->brain = new Brain();
	*this = dog;
	std::cout << "Dog copy constructor called"<< std::endl;
}
Dog &Dog::operator=(const Dog &obj){
	this->Animal::operator=(obj);
	*this->brain = *obj.brain;
	std::cout << "Dog assignment operator"<< std::endl;
	return (*this);
}
void Dog::makeSound(void)const{
	std::cout << "Woof Woof!!!"<< std::endl;
}
Brain* Dog::getBrain(void)const{
	return (this->brain);
}
