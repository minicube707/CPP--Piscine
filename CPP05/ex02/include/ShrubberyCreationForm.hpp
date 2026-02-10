/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:31 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 17:38:22 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
        
    public:
        //Constructor
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &other); 
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

};


