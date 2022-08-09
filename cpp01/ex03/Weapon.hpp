#include <iostream>
#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {
	private:
		std::string type;	
	public:
		Weapon(std::string type);
		~Weapon();
		std::string getType();
		void setType(std::string t);
};
#endif

