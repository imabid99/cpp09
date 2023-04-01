/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:23:33 by imabid            #+#    #+#             */
/*   Updated: 2023/04/01 15:42:27 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) 
{
    BitcoinExchange btc;
    if (argc < 2) 
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open." << filename << std::endl;
        return 1;
    }
    std::string fdata = "data.csv";
    btc.store_data(fdata);
    btc.all_Process(file);

    return 0;
}