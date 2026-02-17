/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:59:46 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/17 18:24:58 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstring>
# include <iostream>

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

        static int check_type(std::string string);
};

