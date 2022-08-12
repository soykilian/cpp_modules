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
	*this = fragtrap;
	std::cout << "FragTrap copy constructor called." << std::endl;
}
FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called." << std::endl;
}

void	FragTrap::attack(std::string const &target){
	std::cout << "FragTrap " + this->name << " attack " + target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}


FragTrap &FragTrap::operator=(FragTrap &obj){
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	return (*this);

}
void FragTrap::highFivesGuys(void){
	std::cout << "Five Guys burgers rock!" << std::endl;
}
