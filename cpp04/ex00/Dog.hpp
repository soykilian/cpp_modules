#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include <iostream>
class Dog : public Animal{
	public:
		Dog();
		~Dog();
		Dog(Dog &animal);
		Dog &operator=(Dog &obj);

		void makeSound(void)const;
};
#endif
