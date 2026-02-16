/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormWrongNameException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:46:43 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/16 14:07:13 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>

class FormWrongNameException : public std::exception 
{
    public:
        //Redefining the what() method of std::exception
        //'throw()': ensures that this function does not throw an exception
        //(equivalent of 'noexcept' in C++11+)
        const char* what() const throw() {return "Error: Form has a wrong name";};
};