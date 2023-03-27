/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:44:41 by imabid            #+#    #+#             */
/*   Updated: 2023/03/27 15:42:44 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PMERGEME_HPP
# define  PMERGEME_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>


class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe const & other);
		PmergeMe& operator=(PmergeMe const & other);

        void lets_sort(char **arg, int ac);
        bool my_Digit(std::string& str);
        // void print();
        template <typename Container>
        void print(Container& c);
};



#endif
