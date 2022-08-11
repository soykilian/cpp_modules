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
	this->name = scavtrap.name;
	this->hit_points = scavtrap.hit_points;
	this->energy_points = scavtrap.energy_points;
	this->attack_damage = scavtrap.attack_damage;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called." << std::endl;
}

void	ScavTrap::attack(std::string const &target){
	std::cout << "ScavTrap " + this->name << " attack " + target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(void){
	std::cout << "Gate keeper mode activated!" << std::endl;
}
