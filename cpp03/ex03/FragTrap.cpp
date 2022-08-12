#include "FragTrap.hpp"

FragTrap::FragTrap(){
	this->name = "fragtrap";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}
FragTrap::FragTrap(std::string name){
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap name constructor called." << std::endl;
}
FragTrap::FragTrap(FragTrap &fragtrap){
	this->name = fragtrap.name;
	this->hit_points = fragtrap.hit_points;
	this->energy_points = fragtrap.energy_points;
	this->attack_damage = fragtrap.attack_damage;
	std::cout << "FragTrap copy constructor called." << std::endl;
}
FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::attack(std::string const &target){
	std::cout << "FragTrap " + this->name << " attack " + target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
void FragTrap::highFivesGuys(void){
	std::cout << "Five Guys burgers rock!" << std::endl;
}
