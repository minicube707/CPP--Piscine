/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:02:26 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/04 19:07:31 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
#include <stdlib.h>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _map_DB;
        std::map<std::string, double> _map_transaction;
        
    public:

        // ====================
        // == Canonical Form ==
        // ====================
        
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        /*--SETTER-&-GETTER--*/
        std::map<std::string, double>& get_map_DB();
        const std::map<std::string, double>& get_map_DB() const;
        std::map<std::string, double>& get_map_transaction();
        const std::map<std::string, double>& get_map_transaction() const;
        
        /*------METHODE------*/
        bool extract_file(const std::string& filename, std::string& file_content);
        
        bool parse_file_content(std::string& file_content, char sep, std::map<std::string, double>& map);
        
        bool check_date(const std::string& date);
        bool check_years(const int& years);
        bool check_month(const int& month);
        bool check_days(const int& years, const int& month, const int& days);
        
        void remove_white_space(std::string& string);

        void display_exchange_rate();
        
};


