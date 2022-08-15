#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*m[4];
		int			n;
	public:
		Character();
		Character(std::string const & name);
		~Character();
		Character(const Character &obj);
		Character &operator=(const Character &obj);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
#endif
