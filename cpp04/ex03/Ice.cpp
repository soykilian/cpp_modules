#include "Ice.hpp" 
#include "ICharacter.hpp" 

Ice::Ice(){
	this->type = "ice";
	std::cout << "Ice constructor called"<< std::endl;
}

Ice::~Ice(){
	std::cout << "Ice destructor called"<< std::endl;
}

Ice::Ice(const Ice &obj)
{
	*this = obj;
	std::cout << "Ice copy constructor called"<< std::endl;
}

Ice &Ice::operator=(const Ice &obj){
	this->type = obj.type;
	std::cout << "Ice assignment operator"<< std::endl;
	return (*this);
}

std::string const & Ice::getType() const{
	return (this->type);
}

AMateria* Ice::clone() const
{
	Ice *ice = new Ice();
	return (ice);
}
void Ice::use(ICharacter& target){
	std::cout << "*shoots an ice bolt at "  << target.getName() << "*" <<std::endl;
}
