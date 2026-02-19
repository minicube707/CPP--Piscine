/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:05:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/19 18:48:49 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static void convert_string_to_char(std::string string)
{
    std::istringstream iss(string);
    char c;
    iss >> c;

    if (!iss.fail())
        cast_char(c);

}
static void convert_string_to_int(std::string string)
{
    std::istringstream iss(string);
    int i;
    iss >> i;

    if (!iss.fail())
        cast_int(i);
    else
        std::cout << "Overflow\n";
}

static void convert_string_to_float(std::string string)
{
    std::istringstream iss(string);
    float f;
    iss >> f;

    if (!iss.fail())
        cast_float(f);
}

static void convert_string_to_double(std::string string)
{
    std::istringstream iss(string);
    double d;
    iss >> d;

    if (!iss.fail())
        cast_double(d);
}

void convert_string_to(std::string string, int type)
{
    if (type == 1)
        convert_string_to_char(string);
        
    else if (type == 2)
        convert_string_to_int(string);

    else if (type == 3)
        convert_string_to_float(string);

    else 
        convert_string_to_double(string);
}