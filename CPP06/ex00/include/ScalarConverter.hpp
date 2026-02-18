/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:59:46 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/18 16:30:46 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstring>
# include <iostream>
# include <bits/stdc++.h> 
# include <sstream>

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

int check_type(std::string &string);
void convert_string_to(std::string string, int type);
