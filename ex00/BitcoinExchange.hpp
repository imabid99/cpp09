#ifndef  BITCOINEXCHANGE_HPP
# define  BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <string>

class  BitcoinExchange
{
	private:

	public:
		 BitcoinExchange();
		 BitcoinExchange( BitcoinExchange const & src);
		 BitcoinExchange&		operator=(  BitcoinExchange const & rhs);
		~BitcoinExchange();
		std::string check_date(std::string key);
		std::string check_btc(std::string value);

};

std::ostream &		operator<<(std::ostream & o, BitcoinExchange const & i);

#endif