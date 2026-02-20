/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:02:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 17:05:15 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void cast_char(char c)
{
    int i = static_cast<int>(c);            // using static_cast for char to int
    float f = static_cast<float>(c);        // using static_cast for char to float
    double d = static_cast<double>(c);      // using static_cast for char to double

    std::cout << "Inital type Char     : " << c << "\n\n";

    std::cout << "Static Cast to Int   : " << i << "\n";
    std::cout << "Static Cast to Float : " << f << "\n";
    std::cout << "Static Cast to Double: " << d << "\n";
}

void cast_int(int i)
{
    char c = static_cast<char>(i);          // using static_cast for int to char
    float f = static_cast<float>(i);        // using static_cast for int to float
    double d = static_cast<double>(i);      // using static_cast for int to double
    
    std::cout << "Inital type Int      : " << i << "\n\n";
    
    print_char(c);
    std::cout << "Static Cast to Float : " << f << "\n";
    std::cout << "Static Cast to Double: " << d << "\n";
}

void cast_float(float f)
{
    char c = static_cast<char>(f);          // using static_cast for float to char
    int i = static_cast<int>(f);            // using static_cast for float to int
    double d = static_cast<double>(f);      // using static_cast for float to double
    
    std::cout << "Inital type Float    : " << f << "f\n\n";
    
    print_char(c);
    std::cout << "Static Cast to Int   : " << i << "\n";
    std::cout << "Static Cast to Double: " << d << "\n";
}

void cast_double(double d)
{
    char c = static_cast<char>(d);          // using static_cast for double to char
    int i = static_cast<int>(d);            // using static_cast for double to int
    float f = static_cast<float>(d);        // using static_cast for double to float
    
    std::cout << "Inital type Double   : " << d << "\n\n";
    
    print_char(c);
    std::cout << "Static Cast to Int   : " << i << "\n";
    std::cout << "Static Cast to Float : " << f << "\n";
}