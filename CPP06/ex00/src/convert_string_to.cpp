/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:05:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/18 16:30:23 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static char convert_string_to_char(std::string string){return string[0];}
static int convert_string_to_int(std::string string){return (std::atoi(string.c_str()));}

static float convert_string_to_float(std::string string)
{
    std::istringstream iss(string);
    float f;
    iss >> f;  // return 0 if failure
    return f;
}

static double convert_string_to_double(std::string string)
{
    std::istringstream iss(string);
    double d;
    iss >> d;  // return 0 if failure
    return d;
}

void convert_string_to(std::string string, int type)
{
    if (type == 1)
        std::cout << "Char: " << convert_string_to_char(string) << "\n";
    
    else if (type == 2)
        std::cout << "Int: " << convert_string_to_int(string) << "\n";

    else if (type == 3)
        std::cout << "Float: " << convert_string_to_float(string) << "\n";

    else 
        std::cout << "Double: " << convert_string_to_double(string) << "\n";
}