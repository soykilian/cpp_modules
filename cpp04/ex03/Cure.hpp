#ifndef CURE_HPP
# define CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class Cure: public AMateria{
	public:
		Cure();
		~Cure();
		std::string const & getType() const; //Returns the materia type
		Cure(const Cure &obj);
		Cure &operator=(const Cure &obj);

		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
