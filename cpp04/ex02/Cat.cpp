#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called"<< std::endl;
}
Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called"<< std::endl;
}
Cat::Cat(const Cat &cat):Animal(cat){
	*this = cat;
	*this->brain = *cat.brain;
	std::cout << "Cat copy constructor called"<< std::endl;
}
Cat &Cat::operator=(const Cat &obj){
	this->type = obj.type;
	std::cout << "Cat assignment operator"<< std::endl;
	return (*this);
}
void Cat::makeSound(void)const{
	std::cout << "*MEow MEow MEow*"<< std::endl;
}
Brain *Cat::getBrain(void)const{
	return (this->brain);
}
