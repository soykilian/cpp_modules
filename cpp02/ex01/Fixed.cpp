#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = fixed.value;
}

Fixed::Fixed(int const num)
{
	std::cout << "Integer constructor called" << std::endl;
	this->value = num << this->frac;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->frac));
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
}


Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return(out);
}
//a constant function does not modify any value of the class
int	Fixed::getRawBits(void) const
{
	return(this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const{
	return((float)this->value / (float)(1 << this->frac));
}
int Fixed::toInt(void)const {
	return(this->value >> this->frac);
}
