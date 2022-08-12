#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp" 
class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap &scavtrap);
		ScavTrap &operator=(ScavTrap &obj);

		void	attack(std::string const &target);
		void guardGate(void);
};
#endif
