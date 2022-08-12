#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->name = "scavtrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl;
}
ScavTrap::ScavTrap(std::string name){
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap name constructor called." << std::endl;
}
ScavTrap::ScavTrap(ScavTrap &scavtrap){
	*this = scavtrap;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj)
{
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	return (*this);
}

void	ScavTrap::attack(std::string const &target){
	std::cout << "ScavTrap " + this->name << " attack " + target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(void){
	std::cout << "Gate keeper mode activated!" << std::endl;
}
