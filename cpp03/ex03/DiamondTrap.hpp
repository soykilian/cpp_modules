#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp" 
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap , public FragTrap{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap &fragtrap);
		DiamondTrap &operator=(DiamondTrap &obj);

		void	attack(std::string const &target);
		void	whoAmI(void);
};
#endif
