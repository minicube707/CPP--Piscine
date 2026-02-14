/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormMissingPartException.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:54:25 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 14:25:40 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>

class FormMissingPartException : public std::exception
{
    private:
        std::string message;

    public:
        //Constructor
        FormMissingPartException(const std::string& missing_part): message("Error: Form doesn't have a " + missing_part) {}

        //Destructor
        ~FormMissingPartException() throw() {}

        //Methode
        const char* what() const throw() {return message.c_str();};
};