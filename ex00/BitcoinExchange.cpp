#include "BitcoinExchange.hpp"

 BitcoinExchange::BitcoinExchange()
{
}

 BitcoinExchange::BitcoinExchange( const  BitcoinExchange & src )
{
}

BitcoinExchange::~BitcoinExchange()
{
}


 BitcoinExchange &				 BitcoinExchange::operator=(  BitcoinExchange const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}
// BitcoinExchange::check_date()
// {
// 	int day, month, year;

// 	if(month < 1 || month > 31)
// 		return 0;
// 	if(month == 2 && day > 28)
// 		return 0;
// 	if()

// }

std::ostream &			operator<<( std::ostream & o,  BitcoinExchange const & i )
{
	return o;
}
