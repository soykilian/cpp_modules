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

void PmergeMe::insertionSortList(std::list<int> &l, int start, int end)
{
	int i, j, key;
	std::list<int>::iterator iterator= l.begin();
    for (i = start +1; i <= end; i++)
    {
        key = *std::next(iterator, i);
        j = i - 1;
        while (j >= start && *std::next(iterator, j) > key)
        {
            *std::next(iterator, j+1)= *std::next(iterator, j);
            j = j - 1;
        }
		*std::next(iterator, j + 1) = key;
    }
}

static void mergeVector(std::vector<int> &v, int start, int mid, int end)
{
    int first_part = mid - start +1;
    int second_part = end - mid;

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

void mergeList(std::list<int> &l, int start, int mid, int end)
{
    int first_part = mid - start +1;
    int second_part = end - mid;

    std::list<int> L;
    std::list<int> R;
    std::list<int>::iterator it = l.begin();
    std::advance(it, start);
    for (int i = 0; i < first_part; i++)
    {
        L.push_back(*it);
        it++;
    }
    for (int j = 0; j < second_part ; j++)
    {
        R.push_back(*it);
        it++;
    }
	it = l.begin();
    int i = 0;
    int j = 0;
    std::advance(it, start);
    while (i < first_part && j < second_part)
    {
        if (L.front() <= R.front())
        {
            *it = L.front();
            L.pop_front();
            i++;
        }
        else
        {
            *it = R.front();
            R.pop_front();
            j++;
        }
        it++;
    }
    while (i < first_part)
    {
        *it = L.front();
        L.pop_front();
        i++;
        it++;
    }
    while (j < second_part)
    {
        *it = R.front();
        R.pop_front();
        j++;
        it++;
    }
}


void PmergeMe::sortList(std::list<int> &l, int start, int end, int thresh)
{
    if(start < end)
    {
        if (end - start + 1 <= thresh)
        {
            insertionSortList(l, start, end);
        }
        else
        {
            int mid = start + (end - start) / 2;
            sortList(l, start, mid, thresh);
            sortList(l, mid+1, end, thresh);
            mergeList(l, start, mid, end);
        }
    }
}

