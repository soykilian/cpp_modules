#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <list>
#include <vector>

class PmergeMe{
	private:
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe	&obj);
		PmergeMe &operator=(PmergeMe &obj);
		void sortVector(std::vector<int> &v, int start, int end, int thresh);
};
#endif
