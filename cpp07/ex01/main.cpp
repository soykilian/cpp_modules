#include "iter.hpp"
template<typename T>
void printArray(const T& var)
{
	std::cout << var << std::endl;
}

int main(void)
{
	int array[4] = {1, 2, 3, 4};
	std::string a[3] = {"Hello", "world", "!"};
	float	b[3] = {10.10f, 3.05f, 9.0f};
	std::cout << "Int array" << std::endl;
	iter(array, sizeof(array)/sizeof(array[0]), &printArray);
	std::cout << "String array" << std::endl;
	iter(a, sizeof(a)/sizeof(a[0]), &printArray);
	std::cout << "Float array" << std::endl;
	iter(b, sizeof(b)/sizeof(b[0]), &printArray);
}
