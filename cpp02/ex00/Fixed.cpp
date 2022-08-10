#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(){

	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = fixed.value;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}
//a constant function does not modify any value of the class
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
