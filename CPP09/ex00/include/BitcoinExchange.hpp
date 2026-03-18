/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:02:26 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/17 14:17:27 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <map>
# include <string>
# include <fstream>
# include <iostream>
# include <sstream>
# include <stdlib.h>
# include <iomanip>

class BitcoinExchange
{
    private:
        static std::map<std::string, std::string> _map_DB;
        static std::map<std::string, std::string> _map_transaction;
        
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        
    public:

        // ====================
        // == Canonical Form ==
        // ====================
        

        /*--SETTER-&-GETTER--*/
        static std::map<std::string, std::string>& get_map_DB();
        static std::map<std::string, std::string>& get_map_transaction();
        
        /*------METHODE------*/
        static bool extract_file(const std::string& filename, std::string& file_content);
        
        static void parse_file_content(std::string& file_content, char sep, std::map<std::string, std::string>& map);
        
        static bool convert_data(const std::string& data, double& ref);
        static bool check_data(const double& ref, bool check_max);
        
        static bool convert_date(const std::string& date, int format_date[3]);
        static bool check_date(const int format_date[3]);
        static bool check_years(const int& years, const int& month, const int& days);
        static bool check_month(const int& years, const int& month, const int& days);
        static bool check_days(const int& years, const int& month, const int& days);
        
        static void remove_white_space(std::string& string);

        static bool check_date_and_data(std::string date, std::string data, bool check_max, double& double_data);

        static void display_exchange_rate();

        static void exchange(const std::string& input_file);
        
};


