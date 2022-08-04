#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie* horde = zombieHorde(4, "Manny");
	horde[0].announce();
	horde[3].announce();

	delete[] horde;
}

