/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:38:27 by imabid            #+#    #+#             */
/*   Updated: 2023/03/31 01:16:32 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  RPN_HPP
# define  RPN_HPP

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

class  Rpn
{
	private:
    	std::stack<int> stk;
	public:
		Rpn();
	    ~Rpn();
		Rpn(Rpn const & other);
		Rpn& operator=(Rpn const & other);
		
		void	all(char *av);
};

#endif