#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp" 
class FragTrap: public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap &fragtrap);
		FragTrap &operator=(FragTrap &obj);

		void	attack(std::string const &target);
		void	highFivesGuys(void);
};
#endif
