/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:40:13 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 16:44:28 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void print_char(char c)
{   
    if (c < 0)
        std::cout << "Display Impossible\n";
        
    else if (c <= 32)
        std::cout << "Non Displayable Char\n";
        
    else
        std::cout << "Static Cast to Char  : " << c << "\n";
}

void print_float(std::string str)
{ 
    if (str[0] == '+')
        str = str.substr(1);
        
    std::cout << "Inital type Float    : " << str << "\n\n";
    
    std::cout << "Static Cast to Char  : Impossible" << "\n";
    std::cout << "Static Cast to Int   : Impossible" << "\n";
    std::cout << "Static Cast to Double: " << str.substr(0, str.length() - 1) << "\n";
}

void print_double(std::string str)
{
    if (str[0] == '+')
        str = str.substr(1);
        
    std::cout << "Inital type Double   : " << str << "\n\n";
    
    std::cout << "Static Cast to Char  : Impossible" << "\n";
    std::cout << "Static Cast to Int   : Impossible" << "\n";
    std::cout << "Static Cast to FLoat : " << str << "f\n";
}