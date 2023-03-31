/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:43 by imabid            #+#    #+#             */
/*   Updated: 2023/03/27 14:36:24 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <stack>
#include <sstream>

int main(int ac, char **av)
{
    Rpn r;
    try
    {
        if(ac < 2)
            throw "Error";
        r.all(av[1]);
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
}