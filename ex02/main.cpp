/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:50 by imabid            #+#    #+#             */
/*   Updated: 2023/03/23 21:45:21 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool my_Digit(std::string& str)
{
    std::string::iterator it = str.begin();
    std::string::iterator end = str.end();
    
     if (it != end && (*it == '+')) 
            ++it;
    for (; it != end; ++it)
    {
        std::cout << *it << std::endl;
        if (!std::isdigit(*it))
            return false;
    }
    return true ;
}

int main(int ac, char **av)
{
    if(ac < 2) 
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::vector<int> a_nbr;
    for(int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        std::cout << "hwll" << std::endl;
        if(!my_Digit(arg))
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        std::stringstream N;
        int nbr;

        N << arg;
        N >> nbr;

        if(nbr < 0)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        a_nbr.push_back(nbr);
    }
    std::sort(a_nbr.begin(), a_nbr.end());
    std::cout << a_nbr.size() << std::endl;
    // for(int i=0; i < a_nbr.size(); i++)
    //     std::cout << a_nbr.at(i) << ' ';
    return 0;
}