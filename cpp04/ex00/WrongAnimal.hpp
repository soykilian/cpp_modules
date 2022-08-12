#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(WrongAnimal &animal);
		WrongAnimal &operator=(WrongAnimal &obj);

		void makeSound(void)const;
		std::string getType(void)const;
};
#endif
