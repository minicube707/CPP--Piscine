/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/17 18:28:01 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
    std::cout << input << "\n";
    std::cout << check_type(input) << "\n";
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static int ft_isnumber(std::string string)
{    
    for (size_t i = 0; i < string.length(); i++)
    {
        if (!ft_isdigit(string[i]))
            return (0);
    }
    return (1);
}

static int ft_isascii(std::string string)
{
    if (string.length() == 1 && 0 <= string[0] && string[0] <= 127)
        return (1);
    return (0);
}

static int ft_isdouble(std::string string)
{
    int i = 0;
    
    if (std::strcmp(string.c_str(), "inf") == 0 || std::strcmp(string.c_str(), "nan") == 0)
        return (1);
        
    //Check the interger part
    while (string[i] != 0 && ft_isdigit(string[i]))
        i++;
    
    //Check if a dot separate the interger part and the decimal part
    if (string[i] != '.')
        return (0);

    i++;
    //Check the decimal part
    while (string[i] != 0 && ft_isdigit(string[i]))
        i++;
    
    if (string[i] != 0)
        return (0);
    return (1);
}

static int ft_isfloat(std::string string)
{   
    if (std::strcmp(string.c_str(), "inff") == 0 || std::strcmp(string.c_str(), "nanf") == 0)
        return (1);
    
    //remove the lasrt char
    if (ft_isdouble(string) && string[string.length() - 1] == 'f')
        return (1);
    return (0);
}

int ScalarConverter::check_type(std::string string)
{
    //Trim white space and + -
    
    if (ft_isnumber(string))
        return (1);
    
    if (ft_isascii(string))
        return (2);

    if (ft_isfloat(string))
        return (3);
        
    if (ft_isdouble(string))
        return (4);
    
    return (0);
}