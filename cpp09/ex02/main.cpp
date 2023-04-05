#include "PmergeMe.hpp"
#include <iomanip>
#include <ctime>
#include <iostream>
void printVector(std::vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
		if (i == 4)
			break;
	} 
	if (v.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;	
}

void printList(std::list<int> v)
{
	std::list<int>::iterator i;
	for (i = v.begin(); i!= v.end(); i++)
		std::cout << *i << " ";
	if (v.size() > 5)
		std::cout << "[...]";
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
		clock_t begin = clock();
		for (int i = 1; i< argc; i++)
		{
			strtol(argv[i], &p, 10);
			val = atoi(argv[i]);
            if (val > 0 && *p == '\0')
			{
				v.push_back(val);
			}
			else
			{
				std::cout << "Error input format" << std::endl;
				return (1);
			}
		}
		std::cout << "Before:\t";
		printVector(v);
		int thresh = v.size() > 15 ? 15 : v.size();
		obj.sortVector(v, 0, v.size()-1, thresh);
		clock_t end = clock();
        double elapsed = double(end - begin) / (CLOCKS_PER_SEC * 10e6);
		std::cout << "After:\t" ;
		printVector(v);
		std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << elapsed*10e6 << " seconds" << std::endl;
	}
	{
		int val;
		char *p;
		clock_t begin = clock();
		for (int i = 1; i< argc; i++)
		{
			strtol(argv[i], &p, 10);
			val = atoi(argv[i]);
            if (val > 0 && *p == '\0')
			{
				l.push_back(val);
			}
			else
			{
				std::cout << "Error input format" << std::endl;
				return (1);
			}
		}
		int thresh = l.size() > 15 ? 15 : l.size();
		obj.sortList(l, 0, l.size()-1, thresh);
		clock_t end = clock();
		//printList(l);
        double elapsed = double(end - begin) / (CLOCKS_PER_SEC * 10e6);
		std::cout << "Time to process a range of " << v.size() << " elements with std::list: " << std::fixed << std::setprecision(6) << elapsed*10e6 << " seconds" << std::endl;

	}
	return(0);
}
