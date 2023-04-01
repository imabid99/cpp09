/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:23:39 by imabid            #+#    #+#             */
/*   Updated: 2023/04/01 15:42:31 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BITCOINEXCHANGE_HPP
# define  BITCOINEXCHANGE_HPP

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

class  BitcoinExchange
{
	private:
		std::map<std::string, float> adata;
	public:
		 BitcoinExchange();
		 BitcoinExchange( BitcoinExchange const & src);
		 BitcoinExchange&		operator=(  BitcoinExchange const & rhs);
		~BitcoinExchange();
		void    	store_data(std::string fdata);
		std::string lets_Trim(const std::string& str);
		bool 		my_Digit(std::string& str);
		int     	check_date(int year, int month, int day);
		int     	check_btc(std::string str);
		float   	btc_calcul(std::string key,std::map<std::string, float>& adata, std::string btc_n);
		void    	all_Process(std::ifstream& file);
};

#endif
