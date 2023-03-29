#include "PmergeMe.hpp"
#include <iostream>
void printVector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
		if (i =4)
			break;
	} 
	//if (v.size() > 5)
		//std::cout << "[...]";
	std::cout << std::endl;	
}
int main(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	std::vector<int> v;
	std::list<int> l;
	PmergeMe obj;
	{
		int val;
		char *p;
		for (int i = 1; i< argc; i++)
		{
			strtol(argv[i], &p, 10);
			val = atoi(argv[i]);
            if (val > 0 && *p == '\0')
				v.push_back(val);
			else
				return (1);
		}
		std::cout << "Before: ";
		printVector(v);
		obj.sortVector(v, 0, argc-1, 15);
		std::cout << "After: " ;
		printVector(v);
	}
	return(0);
}
