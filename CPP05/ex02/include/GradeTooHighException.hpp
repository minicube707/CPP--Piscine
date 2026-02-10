/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:17:55 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 14:46:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>
	
class GradeTooHighException : public std::exception 
{
    public:
        //Redefining the what() method of std::exception
        //'throw()': ensures that this function does not throw an exception
        //(equivalent of 'noexcept' in C++11+)
        const char* what() const throw() {return "Error: Grade Too Hight";};
};
