#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(PmergeMe const & other)
{
    this->vec = other.vec;
    this->deq = other.deq;
    return *this;
}

bool PmergeMe::my_Digit(std::string& str)
{
    std::string::iterator it = str.begin();
    std::string::iterator end = str.end();
    
    if (it != end && (*it == '+')) 
            ++it;
    for (; it != end; ++it)
    {
        if (!std::isdigit(*it))
            return false;
    }
    return true ;
}
template< typename container>
void insertionSort(container &mycnt) {
    int size = mycnt.size();
  for (int step = 1; step < size; step++) {
    int key = mycnt[step];
    int j = step - 1;

    while (j >= 0 && key < mycnt[j]) {
      mycnt[j + 1] = mycnt[j];
      --j;
    }
    mycnt[j + 1] = key;
  }
}

template< typename container, class Iter>
void merge_sort(container &mycont, Iter first, Iter last)
{
    if (last - first > 10) {
        Iter middle = first + (last - first) / 2;
        merge_sort(mycont, first, middle);
        merge_sort(mycont, middle, last);
        std::inplace_merge(first, middle, last);
    }
    else
    {
        insertionSort(mycont);
    }
    
}

void    PmergeMe::lets_sort(char **av,int ac)
{
    for(int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        // std::cout << "hwll" << std::endl;
        if(!my_Digit(arg))
            throw "Error";
        std::stringstream N;
        int nbr;

        N << arg;
        N >> nbr;

        if(nbr < 0)
            throw "Error";                            
        vec.push_back(nbr);
        deq.push_back(nbr);
    }
    std::cout << "Before :";
    merge_sort(vec,vec.begin(),vec.end());
    merge_sort(deq,deq.begin(),deq.end());
    print(vec);
    print(deq);
    // print(deq);
    // std::sort(vec.begin(), vec.end());
    // std::cout << vec.size() << std::endl;
    // for(std::vector<int>::size_type i=0; i < vec.size(); i++)
    //     std::cout << vec.at(i) << ' ';
}

template <typename Container>
void PmergeMe::print(Container& c)
{
    int i = 0;
    typename Container::iterator it;
    for (it = c.begin(); it != c.end(); it++)
    {
        // if (i > 6)
        // {
        //     std::cout << " [...]";
        //     break;
        // }
        std::cout << " " << *it;
        i++;
    }
    std::cout << std::endl;
}