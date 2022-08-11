#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap meme;
	ScavTrap diego("diego");


	diego.attack("meme");
	meme.takeDamage(3);
	meme.beRepaired(5);
	diego.beRepaired(10);
	diego.guardGate();
	return (0);
}
