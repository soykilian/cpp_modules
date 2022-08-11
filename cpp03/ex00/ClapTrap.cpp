#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->name = "claptrap";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Default constructor called." << std::endl;
}
ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Name constructor called." << std::endl;
}
ClapTrap::ClapTrap(ClapTrap &claptrap){
	this->name = claptrap.name;
	this->hit_points = claptrap.hit_points;
	this->energy_points = claptrap.energy_points;
	this->attack_damage = claptrap.attack_damage;
	std::cout << "Copy constructor called." << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << "Destructor called." << std::endl;
}
ClapTrap &ClapTrap::operator=(ClapTrap &obj)
{
    this->name = obj.name;
    return (*this);
}
void	ClapTrap::attack(std::string const &target){
	std::cout << "ClapTrap " + this->name << " attack " + target << ", causing " << this->attack_damage << " points of damage!" << std::endl;

}
void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " + this->name << " receives "<< amount <<" points of damage!" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " + this->name << " repairs with "<< amount<< " points of energy!" << std::endl;
}
