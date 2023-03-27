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
        // std::cout << *it << std::endl;
        if (!std::isdigit(*it))
            return false;
    }
    return true ;
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
    }
    std::cout << "Before :";
    print();
    // std::sort(vec.begin(), vec.end());
    // std::cout << vec.size() << std::endl;
    // for(std::vector<int>::size_type i=0; i < vec.size(); i++)
    //     std::cout << vec.at(i) << ' ';
}

void	PmergeMe::print()
{
	int i = 0;
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		if(i > 6)
		{
			std::cout << " [...]";
			break;
		}
		std::cout << " " << *it;
        i++;
	}
	std::cout << std::endl;
}