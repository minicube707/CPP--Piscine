/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:02:26 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/03 16:43:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <map>
# include <string>
# include <fstream>
# include <iostream>

class BitcoinExchange
{
    private:
        std::map<char, double> _map_price;
        std::map<char, double> _map_transaction;
        
    public:

        // ====================
        // == Canonical Form ==
        // ====================
        
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        /*------METHODE------*/
        bool extract_file(const std::string& file, char sep);
        bool parse_data(const std::string& data, char sep);
        bool check_date();
        bool check_data();
        
};


