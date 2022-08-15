#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main(){
	const Dog* j = new Dog();
    const Cat* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
	j->getBrain()->ideas[0] = "Dog brilliant idea";
	j->getBrain()->ideas[1] = "Dog stupid idea";

	const Dog dog2 = Dog(*j);
	std::cout << std::endl << dog2.getBrain()->ideas[0] << std::endl;
	std::cout << dog2.getBrain()->ideas[1] << std::endl << std::endl;
	j->getBrain()->ideas[0] = "Dog first stupid idea idea";

	std::cout << std::endl << dog2.getBrain()->ideas[0] << std::endl;
	std::cout << dog2.getBrain()->ideas[1] << std::endl << std::endl;

	Dog * dogo = new Dog();

	*dogo = *j;

	std::cout << std::endl << dogo->getBrain()->ideas[0] << std::endl;
	std::cout << dogo->getBrain()->ideas[1] << std::endl << std::endl;

	j->getBrain()->ideas[0] = "Dog brilliant idea";

	std::cout << std::endl << dogo->getBrain()->ideas[0] << std::endl;
	std::cout << dogo->getBrain()->ideas[1] << std::endl << std::endl;

	delete j;
	delete i;
	delete dogo;


	std::cout << std::endl << std::endl;

	Animal *ideas[10];

	for (int i = 0; i < 10 ; i++)
	{
		std::cout << std::endl << std::endl;
		if (i % 2 == 0)
			ideas[i] = new Dog();
		else
			ideas[i] = new Cat();
		std::cout << std::endl << std::endl;
	}

	for (int j = 0;  j < 10; j++)
	{
		ideas[j]->makeSound();
	}

	for (int k = 0;  k < 10; k++)
	{
		delete ideas[k];
	}

    return (0);
}
