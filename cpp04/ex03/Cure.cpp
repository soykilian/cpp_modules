#include "Cure.hpp" 
#include "ICharacter.hpp" 

Cure::Cure(){
	this->type = "cure";
	std::cout << "Cure constructor called"<< std::endl;
}

Cure::~Cure(){
	std::cout << "Cure destructor called"<< std::endl;
}

std::string const & Cure::getType() const{
	return (this->type);
}

AMateria *Cure::clone() const
{
	Cure *ice = new Cure();
	return (ice);
}

Cure::Cure(const Cure &obj){
	*this = obj;
	std::cout << "Cure copy constructor called"<< std::endl;
}

Cure &Cure::operator=(const Cure &obj){
	this->type = obj.type;
	std::cout << "Cure assignment operator"<< std::endl;
	return (*this);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals"  << target.getName() << "'s wounds*"<< std::endl;
}
