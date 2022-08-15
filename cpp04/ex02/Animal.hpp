#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
class Animal{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &animal);
		Animal &operator=(const Animal &obj);

		virtual void makeSound(void)const = 0;
		std::string getType(void)const;
};
#endif
