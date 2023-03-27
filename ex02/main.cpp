/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:50 by imabid            #+#    #+#             */
/*   Updated: 2023/03/27 15:02:59 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pm;
    try
    {
        if(ac < 2) 
            throw  "Error";
        pm.lets_sort(av,ac);
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
    // std::vector<int> a_nbr;
    // for(int i = 1; i < ac; i++)
    // {
    //     std::string arg = av[i];
    //     std::cout << "hwll" << std::endl;
    //     if(!my_Digit(arg))
    //     {
    //         std::cout << "Error" << std::endl;
    //         return 1;
    //     }
    //     std::stringstream N;
    //     int nbr;

    //     N << arg;
    //     N >> nbr;

    //     if(nbr < 0)
    //     {
    //         std::cout << "Error" << std::endl;
    //         return 1;
    //     }
    //     a_nbr.push_back(nbr);
    // }
    // std::sort(a_nbr.begin(), a_nbr.end());
    // std::cout << a_nbr.size() << std::endl;
    // for(int i=0; i < a_nbr.size(); i++)
    //     std::cout << a_nbr.at(i) << ' ';
    return 0;
}