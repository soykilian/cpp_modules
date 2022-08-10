#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(){
	this->value = 0;
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
//	std::cout << "Copy constructor called" << std::endl;
	this->value = fixed.value;
}

Fixed::Fixed(int const num)
{
//	std::cout << "Integer constructor called" << std::endl;
	this->value = num << this->frac;
}

Fixed::Fixed(float const num)
{
//	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->frac));
}

Fixed::~Fixed(){

//	std::cout << "Destructor called" << std::endl;
}
/***************************to_func***********************************/
/*															         */
/*															         */
/*********************************************************************/

float Fixed::toFloat(void) const{
	return((float)this->value / (float)(1 << this->frac));
}
int Fixed::toInt(void)const {
	return(this->value >> this->frac);
}

/*****************OPERATORS*******************************************/
/*															         */
/*															         */
/*********************************************************************/
Fixed& Fixed::operator=(const Fixed &fixed)
{
//	std::cout << "Assignation operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return(out);
}

/************COMPARISON**************/
bool	Fixed::operator>(const Fixed &f)const{
	return this->value > f.getRawBits();
}
bool	Fixed::operator>=(const Fixed &f)const{
	return this->value >= f.getRawBits();
}

bool	Fixed::operator<=(const Fixed &f)const{
	return this->value <= f.getRawBits();

}
bool	Fixed::operator==(const Fixed &f)const{
	return this->value == f.getRawBits();
}
bool	Fixed::operator!=(const Fixed &f)const{
	return this->value != f.getRawBits();
}
/************INCREMENT**************/
Fixed	Fixed::operator++(){
	++(this->value);
	return (*this);
}
Fixed	Fixed::operator--(){
	--(this->value);
	return (*this);
}
Fixed	Fixed::operator++(int){
	Fixed prev(*this);

	++(this->value);
	return (prev);
}
Fixed	Fixed::operator--(int){
	Fixed prev(*this);

	--(this->value);
	return (prev);
}

/*******************ARITMETHIC*******************/
Fixed	Fixed::operator+(const Fixed &obj) const{
	Fixed res(this->toFloat() + obj.toFloat());
	return(res);
}

Fixed	Fixed::operator-(const Fixed &obj) const{
	Fixed res(this->toFloat() - obj.toFloat());
	return(res);
}

Fixed	Fixed::operator*(const Fixed &obj) const{
	Fixed res(this->toFloat() * obj.toFloat());
	return(res);
}

Fixed	Fixed::operator/(const Fixed &obj) const{
	Fixed res(this->toFloat() / obj.toFloat());
	return(res);
}


const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2){
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}
const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2){
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}
Fixed& Fixed::max(Fixed &n1, Fixed &n2){
	if (n1.toFloat() > n2.toFloat())
		return (n1);
	return (n2);
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2){
	if (n1.toFloat() < n2.toFloat())
		return (n1);
	return (n2);
}
//a constant function does not modify any value of the class
/**************************RAW BITS***********************************/
/*															         */
/*															         */
/*********************************************************************/
int	Fixed::getRawBits(void) const{
	return(this->value);
}

void Fixed::setRawBits(int const raw){
	this->value = raw;
}
