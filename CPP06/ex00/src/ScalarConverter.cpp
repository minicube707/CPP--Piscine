/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:56:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/16 18:30:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input)
{
    std::cout << input << "\n";
}

int ft_isdigit(std::string phone_number)
{
    for (size_t i = 0; i < phone_number.length(); i++)
    {
        if (phone_number[i] < '0' || phone_number[i] > '9')
            return (0);
    }
    return (1);
}

static int check_type(std::string input)
{
    
}