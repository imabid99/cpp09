/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:43 by imabid            #+#    #+#             */
/*   Updated: 2023/03/19 16:27:00 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>
#include <stack>
#include <sstream>

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;       
    }
    std::stack<int> stk;
    std::stringstream s(av[1]);
    std::string arg;
    

    while (getline(s, arg, ' '))
    {
        std::stringstream value;
        int               v;
        if(isdigit(arg[0]))
        {
            value << arg;
            value >> v;
            
            if(v < 10 || v > 0)
                stk.push(v);
            else
            {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
        else
        {
            if(stk.size() >= 2)
            {   
            int first = stk.top();
            stk.pop();
            int last = stk.top();
            stk.pop();
            int r;
            switch (arg[0])
            {
            case '+':
                r = last + first;
                break;
            case '-':
                r = last - first;
                break;
            case '*':
                r = last * first;
                break;
            case '/':
                r = last / first;
                break;
            default:
                std::cout << "Error" << std::endl;
                return 1;
            }
            std::cout << "this is v " << r << std::endl;
            stk.push(r);
            }
            else{
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
    }
    if(stk.size() == 1)
    {
        std::cout << stk.top() << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    
    
    
}