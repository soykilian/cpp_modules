#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void){

	std::srand(static_cast<unsigned int>(std::time(0)));
    static int n;
    n = rand()%3;
	switch(n)
	{
		case 0:
			std::cout << "Class A generated" << std::endl;
			return new A;
		case 1:
			std::cout << "Class B generated" << std::endl;
			return new B;
		case 2:
			std::cout << "Class C generated" << std::endl;
			return new C;
	}
	return NULL;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Pointer is type A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Pointer is type B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Pointer is type C" << std::endl;
	else
		std::cout << "Pointer doesn't belong to any class" << std::endl;
}

void identify(Base& p){
	try{
		A &aux = dynamic_cast<A&>(p);
		(void) aux;
		std::cout << "Ref is type A" << std::endl;
		return;
	} catch(...) {}
	try{
		B &aux = dynamic_cast<B&>(p);
		(void) aux;
		std::cout << "Ref is type B" << std::endl;
		return;
	} catch(...) {}
	try{
		C &aux = dynamic_cast<C&>(p);
		(void) aux;
		std::cout << "Ref is type C" << std::endl;
		return;
	} catch(...) {}
	std::cout << "Ref doesn't belong to any class" << std::endl;
}

int main(){
	Base *n1 = generate();

	identify(n1);
	std::cout << "-------------------------------------------------------" << std::endl;
	identify(*n1);
}
