/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:59:46 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 18:27:12 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>    //std::cout
# include <sstream>     //std::istringstream
# include <algorithm>   // count

class ScalarConverter
{
    private:
        // Prevent instantiation of ScalarConverter
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& old);
    
    public:
        // Convert the given input string to all possible scalar types (char, int, float, double)
        static void convert(std::string input);

};

//check_type.cpp
int check_type(std::string &string);

//convert_string_to.cpp 
void convert_string_to(std::string string, int type);

//cast_to.cpp 
void cast_char(char c);
void cast_int(int i);
void cast_float(float f);
void cast_double(double d);

//utils.cpp 
void print_char(char c);
void print_float(std::string str);
void print_double(std::string str);