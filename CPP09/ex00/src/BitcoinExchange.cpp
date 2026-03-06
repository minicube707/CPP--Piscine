/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:03:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/06 18:55:31 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ====================
// == Canonical Form ==
// ====================
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _map_DB(other._map_DB), _map_transaction(other._map_transaction) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this == &other)
        return (*this);
        
    _map_DB = other._map_DB;
    _map_transaction = other._map_transaction; 
    return (*this);
}


/*--SETTER-&-GETTER--*/
std::map<std::string, std::string>& BitcoinExchange::get_map_DB() {return _map_DB;}
const std::map<std::string, std::string>& BitcoinExchange::get_map_DB() const{ return _map_DB;}
std::map<std::string, std::string>& BitcoinExchange::get_map_transaction() {return _map_transaction;}
const std::map<std::string, std::string>& BitcoinExchange::get_map_transaction() const {return _map_transaction;} 

/*------METHODE------*/
bool BitcoinExchange::extract_file(const std::string& filename, std::string& file_content)
{
    //Reading
    std::ifstream f(filename.c_str());
    if (!f.is_open())
    {
        std::cerr << "Error: can't open " << filename << std::endl;
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
    
    file_content = data;
    
    return (false);
}

bool BitcoinExchange::parse_file_content(std::string& file_content, char sep, std::map<std::string, std::string>& map)
{
    //Remove the header
    file_content.erase(0, file_content.find('\n') + 1);

    std::string line;
    std::string date;
    std::string data;
    std::string::size_type pos_new_line;
    
    while (!file_content.empty())
    {   
        pos_new_line = file_content.find('\n');
        
        line = file_content.substr(0, pos_new_line);
        remove_white_space(line);

        file_content.erase(0, pos_new_line + 1);
           
        date = line.substr(0, line.find(sep));
        data = line.substr(line.find(sep)+1);
        
        //If the separator and the value is missing, then data copy date, clear to safe the calcul exchange
        if (date == data)
            data.clear();
        
        if (!data.empty() || !date.empty())
            map.insert(std::make_pair(date, data)); //Syntaxe for cpp98++
    }
    return (false);
}

bool BitcoinExchange::convert_data(const std::string& data, double& ref)
{
    std::istringstream iss(data);
    iss >> ref;

    if (!iss.fail() && iss.eof())
        return false;
        
    std::cerr << "Error: Can't convert (" << data << ") to type double\n";
    return true;
}

bool BitcoinExchange::check_data(const double& ref, bool check_max)
{
    if (0 > ref)
    {
        std::cerr << "Error: not a positive number (" << ref << ")\n";
        return true;
    }

    if (ref > 1000 && check_max)
    {
        std::cerr << "Error: too large a number (" << ref << ")\n";
        return true;
    }
    return false;
}

bool BitcoinExchange::convert_date(const std::string& date, int format_date[3])
{
    char sep = '-';
    
    std::string tmp;
    std::stringstream iss(date);
    int i = 0;
    while (getline(iss, tmp, sep))
    {
        std::istringstream convert(tmp);
        convert >> format_date[i++];

        if (convert.fail())
        {
            std::cerr << "Error: Can't convert (" << tmp << ") to int\n";
            return (true);
        }
    }
    return (false);
}

bool BitcoinExchange::check_date(const int format_date[3])
{
    if (check_years(format_date[0]))
        return (true);
    
    if (check_month(format_date[1]))
        return (true);
    
    if (check_days(format_date[0], format_date[1], format_date[2]))
        return (true);
        
    return (false);
}

bool BitcoinExchange::check_years(const int& years)
{
    if (2009 <= years)
        return (false); 
        
    std::cerr << "Error: Years out of range (" << years << ")\n";
    return (true);
}

bool BitcoinExchange::check_month(const int& month)
{
    if (1 <= month && month <= 12)
        return (false); 
        
    std::cerr << "Error: Mouth out of range (" << month << ")\n";
    return (true);
}

bool BitcoinExchange::check_days(const int& years, const int& month, const int& days)
{
    int day_by_mouth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     
    //Leap Years
    if (years % 4 == 0 && month == 2)
        day_by_mouth[1] = 29;
        
    if (1 <= days && days <= day_by_mouth[month - 1])
        return (false); 
    
    std::cerr << "Error: Days out of range (" << days << ")\n";
    return (true);
}

void BitcoinExchange::remove_white_space(std::string& string)
{
    for (std::size_t i = 0; i < string.length(); i++)
    {
        if (string[i] == ' ' || string[i] == '\t')
            string.erase(string.begin() + i--);
    }
}

bool BitcoinExchange::check_date_and_data(std::string date, std::string data, bool check_max, double& double_data)
{
    int tab_date[3] = {0};

    if (convert_date(date, tab_date))
        return (true);
        
    if (check_date(tab_date))
        return (true);
    
    if (convert_data(data, double_data))
        return (true);

    if (check_data(double_data, check_max))
        return (true);
        
    return (false);
}

void BitcoinExchange::display_exchange_rate()
{
    std::map<std::string, std::string>::iterator it_DB;
    std::map<std::string, std::string>::iterator it_tr;
    
    double double_DB;
    double double_tr;
    double calcul_exchange_rate;
    
    std::string date_DB;
    std::string data_DB;
    std::string date_tr;
    std::string data_tr;
    
    //For each value in input.txt search the same date or lower in data.csv
    for (it_tr = _map_transaction.begin(); it_tr != _map_transaction.end(); ++it_tr)
    {
        date_tr = it_tr->first;
        data_tr = it_tr->second;
        
        std::cout << "\n";
        std::cout << "Key: " << date_tr << " | Value: " << data_tr << std::endl;
        
        if (check_date_and_data(date_tr, data_tr, true, double_tr))
            continue;
            
        it_DB = _map_DB.upper_bound(date_tr);
        if (it_DB == _map_DB.begin())
        {
            std::cerr << "Error: Lower date not find (" << date_tr << ")\n";
            continue;
        }
            
        it_DB--;
        date_DB = it_DB->first;
        data_DB = it_DB->second;
        
        std::cout << "Key: " << date_DB << " | Value: " << data_DB << std::endl;

        if (check_date_and_data(date_DB, data_DB, false, double_DB))
            continue;

        std::cout << date_tr << " => "; 
        std::cout << data_tr << " = ";
        
        calcul_exchange_rate = double_DB * double_tr;
        std::cout << calcul_exchange_rate << "\n";
    }
}