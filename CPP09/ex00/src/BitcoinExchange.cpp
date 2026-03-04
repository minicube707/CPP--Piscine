/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:03:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/04 19:00:25 by fmotte           ###   ########.fr       */
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
std::map<std::string, double>& BitcoinExchange::get_map_DB() {return _map_DB;}
const std::map<std::string, double>& BitcoinExchange::get_map_DB() const{ return _map_DB;}
std::map<std::string, double>& BitcoinExchange::get_map_transaction() {return _map_transaction;}
const std::map<std::string, double>& BitcoinExchange::get_map_transaction() const {return _map_transaction;} 

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

bool BitcoinExchange::parse_file_content(std::string& file_content, char sep, std::map<std::string, double>& map)
{
    //Remove the header
    file_content.erase(0, file_content.find('\n') + 1);

    std::string line;
    std::string date;
    std::string data;
    double ref;
      
    while (!file_content.empty())
    {   
        std::string::size_type pos_new_line = file_content.find('\n');
        
        line = file_content.substr(0, pos_new_line);
        remove_white_space(line);

        file_content.erase(0, pos_new_line + 1);
           
        date = line.substr(0, line.find(sep));
        data = line.substr(line.find(sep)+1);
        
        if (!data.empty() && !date.empty())
        {
            if (check_date(date))
            {
                std::cerr << "Error: Wrong date\n";
                return (true);
            }
            

            ///Check cast double
            std::istringstream iss(data);
            iss >> ref;
            
            // if data is empty -> data = double (nan)
            
            //Check for the doublons  
            map.insert(std::make_pair(date, ref)); //Syntaxe for cpp98++
        }
    }
    return (false);
}

bool BitcoinExchange::check_date(const std::string& date)
{
    char sep = '-';
    int format_date[3];
    
    std::string tmp;
    std::stringstream iss(date);
    int i = 0;
    while (getline(iss, tmp, sep))
        format_date[i++] = std::atoi(tmp.c_str());
    
    return (false);
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
    if (2009 <= years && years <= 20022)
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

void BitcoinExchange::display_exchange_rate()
{
    std::map<std::string, double>::iterator it_tr;
    double calcul_exchange_rate;
    
    //For each value in DB search the same date ot lower in input.txt
    for (std::map<std::string, double>::iterator it_DB = _map_DB.begin(); it_DB != _map_DB.end(); ++it_DB)
    {
        std::cout << it_DB->first << " => "; 
        std::cout << it_DB->second << " = ";
        
        it_tr = _map_transaction.upper_bound(it_DB->first);
        calcul_exchange_rate = it_DB->second * it_tr->second;
        std::cout << calcul_exchange_rate << "\n";
    }
}