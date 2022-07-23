#include "Zombie.hpp"
#include <iostream>

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

int main(void)
{
	Zombie mani("Mani");
	Zombie yegres("Yegres");

	yegres.announce();
	mani.announce();

	randomChump("Keko");
	Zombie* mavi = newZombie("Mavi");
	mavi->announce();
	delete(mavi);
}
