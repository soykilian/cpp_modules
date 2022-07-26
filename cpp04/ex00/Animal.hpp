#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
class Animal{
	protected:
		std::string type;
	public:
		Animal();
		~Animal();
		Animal(Animal &animal);
		Animal &operator=(Animal &obj);

		virtual void makeSound(void)const;
		std::string getType(void)const;
};
#endif
