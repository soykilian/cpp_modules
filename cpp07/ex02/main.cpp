#include "Array.hpp"

int main(void)
{
	Array<int> *a = new Array<int>();
	std::cout << "Int Array -> Size of a " << a->getSize() << std::endl;
	Array<float> b = Array<float>(5);

	std::cout << "Float Array -> Size of b " << b.getSize() << std::endl;
	std::cout << "First element of b " << b[0] << std::endl;
	try{
		std::cout << "Sixth element of b " << b[6] << std::endl;
	}catch(std::exception &e){
		std::cout << "Tried to acces element 5 of b but threw an exception"<< e.what() << std::endl;
	}

	delete a;

}
