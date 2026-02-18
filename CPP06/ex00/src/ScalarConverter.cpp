/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/18 16:35:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
    int type;
    
    std::cout << "Input" << input << "\n";
    type = check_type(input);
    
    if (type == 0)
    {
        std::cout << "Error input\n";
        return;
    }
    convert_string_to(input, type);
    std::cout << "\n";
}

