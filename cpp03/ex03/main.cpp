#include "FragTrap.hpp"

int main(void)
{
	FragTrap meme;
	FragTrap diego("diego");


	diego.attack("meme");
	meme.takeDamage(3);
	meme.beRepaired(5);
	diego.beRepaired(10);
	diego.highFivesGuys();
	return (0);
}
