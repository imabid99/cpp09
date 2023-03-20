/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:23:48 by imabid            #+#    #+#             */
/*   Updated: 2023/03/20 19:19:37 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

 BitcoinExchange::BitcoinExchange()
{
}

 BitcoinExchange::BitcoinExchange( const  BitcoinExchange & src )
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

 BitcoinExchange &				 BitcoinExchange::operator=(  BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->_value = rhs._value;
	}
	return *this;
}

std::string BitcoinExchange::lets_Trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}

bool BitcoinExchange::my_Digit(std::string& str)
{
    std::string::iterator it = str.begin();
    std::string::iterator end = str.end();
    int p = false;
    if (it != end && (*it == '-' || *it == '+')) 
        ++it;
    for (; it != end; ++it)
    {
        if (*it == '.') 
        {
           if (p) 
               return false;
           else
               p = true;
        } 
        else if (!std::isdigit(*it))
            return false;
    }
    return true;
}

int     BitcoinExchange::check_date(int year, int month, int day)
{
    if(year < 2009 || year > 2022)
        return 0;
    else if(month < 1 || month > 12)
        return 0;
    else if(day < 1 || day > 31)
        return 0;
    else if(month == 2 && day > 28)
        return 0;
    else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return 0;
    return 1;
}

int     BitcoinExchange::check_btc(std::string str)
{
    if(atof(str.c_str()) < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    if (atof(str.c_str()) > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    return 1;
}

void    BitcoinExchange::store_data(std::string fdata, std::map<std::string, float>& adata)
{
    std::ifstream   f(fdata);
    std::string     line;
    std::string     key;
    std::string     value;
    int             pos;
    float           va;
    if(!f.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return ;
    }
    while (std::getline(f,line))
    {
        pos = line.find(',');
        key = line.substr(0, pos);
        value = line.substr(pos + 1);
        va = atof(value.c_str());
        adata[key] = va;
    }
}

float     BitcoinExchange::btc_calcul(std::string key, std::map<std::string, float>& adata, std::string btc_n)
{
    std::map<std::string, float>::iterator it;
    float btc_val;
    it = adata.find(key);
    if(it != adata.end())
    {
        btc_val = it->second * atof(btc_n.c_str());
        return btc_val;
    }
    else
    {
        
        it = adata.lower_bound(key);
        if(adata.begin() != it)
            it--;
        btc_val = it->second * atof(btc_n.c_str());
        return btc_val;
    }
    return 1;
}

void    BitcoinExchange::all_Process(std::ifstream& file, std::map<std::string, float>& adata)
{
    std::string     line, key, value, datakey, dataval, firstline;

    std::getline(file, firstline);
    if (firstline.substr(0, 6) == "date | value")
    {
        std::cout << "Error in first line : " << firstline << "\n";
        std::getline(file, firstline);
    }
    while (std::getline(file, line)) 
    {
        int                 pos;
        
        pos = line.find('|');
        key = line.substr(0, pos);
        value = line.substr(pos + 1);
        key = lets_Trim(key);
        value = lets_Trim(value);
        int ryear, rmonth, rday;
        std::stringstream   ss(key);
        std::stringstream   y, m, d;
        std::string         year, month, day;

        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day);
        
        if(!my_Digit(year) || !my_Digit(month) || !my_Digit(day) || !my_Digit(value) || key.size() != 10)
        {
            std::cout << "Error : bad input " << line << std::endl;
            continue;
        }
        else
        {
            y << year;
            m << month;
            d << day;
            y >> ryear;
            m >> rmonth;
            d >> rday; 
            if(!check_date(ryear, rmonth, rday) || value.empty())
            {
                std::cout << "Error : bad input " << line << std::endl;
                continue;
            }
            if(!check_btc(value))
                continue;
        }
        std::cout << year << "-" << month << '-' << day << " => " << value << " = " << btc_calcul(key, adata, value) << std::endl; 
    }
}
