/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:58:24 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 17:06:24 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static bool ft_isnumber(std::string string)
{    
    for (size_t i = 0; i < string.length(); i++)
    {
        if (!isdigit(string[i]))
            return (false);
    }
    return (true);
}

static bool ft_isascii(std::string string)
{
    if (string.length() == 1 && 0 <= string[0] && string[0] <= 127)
        return (true);
    return (false);
}

static bool ft_isdouble(std::string string)
{ 
    //Check if the string is just a dot
    if (string == ".")
        return (false);
        
    //Check First the case 'inf' and 'nan'
    if (string == "inf"|| string == "nan")
        return (true);
    
    //Check if a dot separate the interger part and the decimal part
    if (count(string.begin(), string.end(), '.') != 1)
        return (false);
    
    //Check the interger part
    size_t len_interger_part = string.find('.');
    if (ft_isnumber(string.substr(0, len_interger_part)) == 0)
        return (false);
        
    //Check the decimal part
    if (ft_isnumber(string.substr(len_interger_part + 1, string.length())) == 0)
        return (false);
        
    return (true);
}

static bool ft_isfloat(std::string string)
{   
    //remove the last char
    std::string tmp = string.substr(0, string.length() - 1);
    
    //Check if it's a double ending with an f
    if (ft_isdouble(tmp) && string[string.length() - 1] == 'f')
        return (true);
    return (false);
}

void ltrim(std::string& s) 
{
    //Skip if the len of string is 1.
    //For user can test with space, tab, ...
    if (s.length() == 1)
        return;
    
    //Else remove withespace at the begining of the string
    for (size_t i = 0; i < s.length(); i++)
    {
        if ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
        {
            s.erase(i, 1);
            i--;
        }           
        else
            break;
    }
}

int check_type(std::string &string)
{
    //Remove withespace
    ltrim(string);
    
    //Check empty string
    if (string.empty())
    {
        std::cout << "Empty string\n";
        return (0);
    }
      
    if (ft_isascii(string))
        return (1);
    
    //Skip plus and minus
    std::string tmp =  string;
    if (string[0] == '+' || string[0] == '-')
        tmp = string.substr(1);

    if (ft_isnumber(tmp))
        return (2);
        
    if (ft_isfloat(tmp))
        return (3);
        
    if (ft_isdouble(tmp))
        return (4);
    
    return (0);
}
