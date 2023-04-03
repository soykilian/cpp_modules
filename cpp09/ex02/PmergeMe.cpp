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
    for (i = start +1; i <= end; i++)
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
    int first_part = mid - start +1;
    int second_part = end - mid;

	std::cout << mid << std::endl;
    std::vector<int> L(first_part);
	std::vector<int> R(second_part);
    for (int i = 0; i < first_part; i++)
        L[i] = v[start + i];
    for (int j = 0; j < second_part ; j++)
        R[j] = v[mid + j + 1];
    int i = 0;
    int j = 0;
    int k = start;
    while (i < first_part && j < second_part)
    {
        if (L[i] <= R[j])
            v[k] = L[i++];
        else
            v[k] = R[j++];
        k++;
    }
	std::cout << j << " " << R.size()<< std::endl;
    while (i < first_part)
        v[k++] = L[i++];
    while (j < second_part)
        v[k++] = R[j++];

}

void PmergeMe::sortVector(std::vector<int> &v, int start, int end, int thresh)
{
    if (start < end)
    {
        if (end - start + 1 <= thresh)
		{
            insertionSortVector(v, start, end);
		}
        else
        {
            int mid = start + (end - start) / 2;
            sortVector(v, start, mid, thresh);
            sortVector(v, mid+1, end, thresh);
            mergeVector(v, start, mid, end);
        }
    }
}
// Function that sorts a std::list<int> using insertion sort algorithm using std::list<int>::iterator that receives int start, int end and the std::list<int> l
static void insertionSortList(std::list<int> &l, std::list<int>::iterator start, std::list<int>::iterator end)
{
    std::list<int>::iterator i;
    std::list<int>::iterator j;
    std::list<int>::iterator key;
    for (i = std::next(start); i != std::next(end); i++)
    {
        key = i;
        j = std::prev(i);
        while (j != std::prev(start) && *j > *key)
        {
            std::iter_swap(std::next(j), key);
            j--;
            key--;
        }
    }
}

// Function that merges two sorted std::list<int> using std::list<int>::iterator and std::next() function
static void mergeList(std::list<int> &l, std::list<int>::iterator start, std::list<int>::iterator mid, std::list<int>::iterator end)
{
    std::list<int> L;
    std::list<int> R;
    std::list<int>::iterator i;
    std::list<int>::iterator j;
    for (i = start; i != std::next(mid); i++)
        L.push_back(*i);
    for (j = std::next(mid); j != std::next(end); j++)
        R.push_back(*j);
    i = L.begin();
    j = R.begin();
    while (i != L.end() && j != R.end())
    {
        if (*i <= *j)
        {
            *start = *i;
            i++;
        }
        else
        {
            *start = *j;
            j++;
        }
        start++;
    }
    while (i != L.end())
    {
        *start = *i;
        i++;
        start++;
    }
    while (j != R.end())
    {
        *start = *j;
        j++;
        start++;
    }
}

