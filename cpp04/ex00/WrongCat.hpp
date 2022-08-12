#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat &animal);
		WrongCat &operator=(WrongCat &obj);

		void makeSound(void)const;
};
#endif
