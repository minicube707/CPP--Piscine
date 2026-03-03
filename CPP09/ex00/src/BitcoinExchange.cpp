/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:03:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/03 16:52:57 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ====================
// == Canonical Form ==
// ====================
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _map_price(other._map_price), _map_transaction(other._map_transaction) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return (*this);
        
    _map_price = other._map_price;
    _map_transaction = other._map_transaction; 
    return (*this);
}

/*------METHODE------*/
bool BitcoinExchange::extract_file(const std::string& filename, char sep)
{
    //Reading
    std::ifstream f(filename.c_str());
    if (!f.is_open())
    {
        std::cout << "Error: can't open " << filename << std::endl;
        return (true);
    }
    
    /*Copy into tmp*/
    std::string line;
    std::string data;
    while (std::getline(f, line))
    {
        if (!f.eof())
            line.append("\n");
        data.append(line);
    }
    f.close();
    
    return (parse_data(data, sep));
}

bool BitcoinExchange::parse_data(const std::string& data, char sep)
{
    std::string line;
    while (!data.empty())
    {   
        line = data.find('\n');
        if (line.find(sep) == std::string::npos)
        {
            std::cout << "ERROR mis sep\n";
            return (true);
        }

        std::cout << "\n";
        std::cout << "Date: " << line.substr(0, line.find(sep)) << "\n";
        std::cout << "Data: " << line.substr(line.find(sep)+1) << "\n";
    }  
    return (false);
}