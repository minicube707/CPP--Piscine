/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormNotSignedException.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:03:31 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/11 15:04:01 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>

class FormNotSignedException : public std::exception 
{
    public:
        //Redefining the what() method of std::exception
        //'throw()': ensures that this function does not throw an exception
        //(equivalent of 'noexcept' in C++11+)
        const char* what() const throw() {return "Error: Form is not signed";};
};