#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap meme;
	ClapTrap diego("diego");

	diego.attack("meme");
	meme.takeDamage(3);
	meme.beRepaired(5);
	diego.beRepaired(10);
	return (0);
}
