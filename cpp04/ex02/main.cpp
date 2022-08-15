#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main(){
//	const Animal	*a = new Animal();
	const Dog		*b=  new Dog();
	const Dog		c = Dog(*b);
    return (0);
}
