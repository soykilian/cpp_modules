#ifndef ICE_HPP
# define ICE_HPP
#include <iostream>
#include "AMateria.hpp"

class Ice: public AMateria{
	public:
		Ice();
		~Ice();
		Ice &operator=(const Ice &obj);
		Ice(const Ice &obj);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif
