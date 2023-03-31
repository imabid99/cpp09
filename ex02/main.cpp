/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:50 by imabid            #+#    #+#             */
/*   Updated: 2023/03/31 15:55:21 by imabid           ###   ########.fr       */
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
    return 0;
}