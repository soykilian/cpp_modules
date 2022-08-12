#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called"<< std::endl;
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called"<< std::endl;
}
WrongCat::WrongCat(WrongCat &cat){
	*this = cat;
	std::cout << "WrongCat copy constructor called"<< std::endl;
}
WrongCat &WrongCat::operator=(WrongCat &obj){
	this->type = obj.type;
	std::cout << "WrongCat assignment operator"<< std::endl;
	return (*this);
}
void WrongCat::makeSound(void)const{
	std::cout << "*MEow MEow MEow*"<< std::endl;
}
