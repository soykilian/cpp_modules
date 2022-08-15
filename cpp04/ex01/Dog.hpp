#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
class Dog : public Animal{
	private:
		Brain* brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &obj);
		void makeSound(void)const;
		Brain *getBrain(void)const;
};
#endif
