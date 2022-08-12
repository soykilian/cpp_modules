#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap meme;
	DiamondTrap diego("diego");


	diego.attack("meme");
	meme.takeDamage(3);
	meme.beRepaired(5);
	diego.beRepaired(10);
	diego.highFivesGuys();
	diego.whoAmI();
	return (0);
}
