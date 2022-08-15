#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
	this->type = type;
}
AMateria::AMateria(){
	std::cout << "AMateria constructor called"<< std::endl;
}
AMateria::~AMateria(){
	std::cout << "AMateria destructor called"<< std::endl;
}
std::string const & AMateria::getType() const{
	return (this->type);
}
void AMateria::use(ICharacter& target){
	(void)target;
	std::cout << "use method"  << std::endl;
}
