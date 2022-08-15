#include "Character.hpp"

Character::Character(){
	this->name = "Default";
	this->n = 0;
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character(){
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &obj){
	*this = obj;
	std::cout << "Character copy constructor called"<< std::endl;
}

Character::Character(std::string const & name){
	this->name = name;
	this->n = 0;
	std::cout << "Character constructor called" << std::endl;
}

Character &Character::operator=(const Character &obj){
	this->name = obj.name;
	this->n = obj.n;
	*this->m = *obj.m;
	std::cout << "Character assignment operator"<< std::endl;
	return (*this);
}

std::string const & Character::getName() const{
	return (this->name);
}

void Character::equip(AMateria* m){
	if (this->n > 3)
		return;
	std::cout << "* equiped " << m->getType() << " in slot number " << this->n + 1 << " *" << std::endl;
	this->m[this->n]=m;
	this->n++;
}

void Character::unequip(int idx){
	if (this->n > idx)
		this->m[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->n > idx)
		this->m[idx]->use(target);
}
