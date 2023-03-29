#include "PmergeMe.hpp" 
PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &obj){
	(void) obj;
}

PmergeMe &PmergeMe::operator=(PmergeMe &obj){
	(void) obj;
	return (*this);
}
void insertionSortVector(std::vector<int> &v, int start, int end)
{
    int i, j, key;
    for (i = start ; i < end; i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= start && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

static void mergeVector(std::vector<int> &v, int start, int mid, int end)
{
    int first_part = mid - start -1;
    int second_part = end - mid;

	std::cout << mid << std::endl;
    std::vector<int> L(first_part);
	std::vector<int> R(second_part);
    for (int i = 0; i < first_part; i++)
        L[i] = v[start + i];
    for (int j = 0; j < second_part ; j++)
	{
		//std::cout << mid + 1 + j << std::endl;
        R[j] = v[mid + j];
	}
    int i = 0;
    int j = 0;
    int k = start;
    while (i < first_part && j < second_part)
    {
		std::cout << L[i]<<" "<< R[j]<< std::endl;
        if (L[i] <= R[j])
            v[k] = L[i++];
        else
            v[k] = R[j++];
        k++;
    }
	std::cout << j << " " << R.size()<< std::endl;
	std::cout << k << std::endl;
    while (i < first_part)
        v[k++] = L[i++];
    while (j < second_part)
        v[k++] = R[j++];

}

void PmergeMe::sortVector(std::vector<int> &v, int start, int end, int thresh)
{
	//std::cout << "start: " << start  << " end: " << end << std::endl;
    if (start < end)
    {
        if (end - start + 1 <= thresh)
		{
            insertionSortVector(v, start, end);
		}
        else
        {
            int mid = start + (end - start) / 2;
            sortVector(v, start, mid-1, thresh);
            sortVector(v, mid, end, thresh);
            mergeVector(v, start, mid, end);
        }
    }
}
