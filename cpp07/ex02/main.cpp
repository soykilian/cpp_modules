#include "Array.hpp"

int main(void)
{
	Array<int> *a = new Array<int>();
	std::cout << "Size of a " << a->getSize() << std::endl;
	Array<float> b = Array<float>(5);
	std::cout << "Size of b " << b.getSize() << std::endl;
	delete a;

}
