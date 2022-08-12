#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	this->name = "DiamondTrap";
	this->hit_points = FragTrap::hit_points;
	this->ClapTrap::name = std::string("DiamondTrap").append("_clap_name");
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
	this->name = name;
	this->ClapTrap::name = name.append("_clap_name");
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &diamond){
	*this = diamond;
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}
DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called." << std::endl;
}
DiamondTrap &DiamondTrap::operator=(DiamondTrap &obj){
	this->name = obj.name;
	this->ClapTrap::name = obj.ClapTrap::name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	return (*this);
}

void DiamondTrap::attack(std::string const &target){
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void){
	std::cout << "DiamondTrap " << this->name << " inherits from " << this->ClapTrap::name << std::endl;
	
}
