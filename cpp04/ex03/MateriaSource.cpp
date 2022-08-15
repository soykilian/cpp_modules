#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	this->n = 0;
	std::cout << "MateriaSource constructor called"<< std::endl;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource destructor called"<< std::endl;
}

void MateriaSource::learnMateria(AMateria* m){
	if (this->n > 3)
		return ;
	this->m[this->n]=m;
	this->n++;
}
AMateria *MateriaSource::createMateria(std::string const & type){
	if (this->n <= 3)
	{
		for (int i = 0 ; i < n ; i++)
		{
			if (this->m[i]->getType() == type)
				return (this->m[i]->clone());
		}
	}
	return (NULL);
}
