#ifndef BRAIN_HPP
# define BRAIN_HPP
#include "Animal.hpp"
#include <iostream>
class Brain {
	public:
		Brain();
		~Brain();
		Brain(const Brain &brain);
		Brain &operator=(const Brain &obj);
		std::string ideas[100];
};
#endif
