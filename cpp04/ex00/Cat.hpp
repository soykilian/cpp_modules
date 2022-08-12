#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
class Cat : public Animal{
	public:
		Cat();
		~Cat();
		Cat(Cat &animal);
		Cat &operator=(Cat &obj);

		void makeSound(void)const;
};
#endif
