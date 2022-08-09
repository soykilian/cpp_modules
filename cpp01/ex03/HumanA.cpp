#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
}
HumanA::~HumanA(){}

void HumanA::attack()
{
	std::string type = this->weapon.getType();
	std::cout << this->name << "attacks with his" << type << std::endl;
}
