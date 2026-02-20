/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_to.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:05:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 16:38:26 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

static void convert_string_to_char(std::string string){cast_char(string[0]);}

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
    //Verify if string is a Nan or an Inf
    std::string list_exception_case[] = {"nanf", "+nanf", "-nanf", "inff", "+inff", "-inff"};
    size_t lenght_list = sizeof(list_exception_case) / sizeof(list_exception_case[0]); // Get the number of element in array
    
    //Check if there is a match with the list
    for (size_t i = 0; i < lenght_list; i++)
    {
        if (list_exception_case[i] == string)
            return(print_float(string));
    }
        
    //Normal Case
    std::istringstream iss(string);
    float f;
    iss >> f;

    if (!iss.fail())
        cast_float(f);
    else
        std::cout << "Overflow\n";
}

static void convert_string_to_double(std::string string)
{
    //Verify if string is a Nan or an Inf
    std::string list_exception_case[] = {"nan", "+nan", "-nan", "inf", "+inf", "-inf"};
    size_t lenght_list = sizeof(list_exception_case) / sizeof(list_exception_case[0]); // Get the number of element in array
    
    //Check if there is a match with the list
    for (size_t i = 0; i < lenght_list; i++)
    {
        if (list_exception_case[i] == string)
            return(print_double(string));
    }
    
    //Normal Case
    std::istringstream iss(string);
    double d;
    iss >> d;

    if (!iss.fail())
        cast_double(d);
    else
        std::cout << "Overflow\n";
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