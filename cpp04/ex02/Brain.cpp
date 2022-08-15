#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called"<< std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called"<< std::endl;
}

Brain::Brain(const Brain &brain){
	for (size_t i=0; i < brain.ideas->size(); i++)
		this->ideas[i] = brain.ideas[i];
	std::cout << "Brain copy constructor called"<< std::endl;
}

Brain &Brain::operator=(const Brain &obj){
	for (size_t i=0; i < obj.ideas->size(); i++)
		this->ideas[i] = obj.ideas[i];
	std::cout << "Brain assignment operator"<< std::endl;
	return (*this);
}
