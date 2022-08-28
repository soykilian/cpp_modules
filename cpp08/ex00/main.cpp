#include "easyfind.hpp"
#include <array>
#include <vector>
#include <set>

template<typename T>
void printContainer(const T obj)
{
	typename T::const_iterator elem;
	for(elem = obj.begin(); elem != obj.end(); elem++){
		std::cout << *elem << " ";
	}
	std::cout << std::endl;
}

int main (void)
{
	std::array<int, 5> g1 = {1,3,5,7,9};
	std::cout << "Array of ints created:"<< std::endl;
	printContainer(g1);
	try{
		std::cout << easyfind(g1, 5) << std::endl;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::vector<int> g2;
	std::cout << "Vector of ints created:"<< std::endl;
	for (int i = 1; i <= 5; i++)
        g2.push_back(i);
	printContainer(g2);
	try{
		std::cout << easyfind(g2, 5) << std::endl;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::set<int> g3;
	g3.insert(10);
	g3.insert(15);
	g3.insert(1);
	g3.insert(4);
	std::cout << "Set of ints created:"<< std::endl;
	printContainer(g3);
	try{
		std::cout << easyfind(g3, 5) << std::endl;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
