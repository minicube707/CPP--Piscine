/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:44:22 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/16 15:03:38 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdexcept>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        //Constructor
        Intern();
        
        //Destructor, Copy Constructor, Copy Constructor
        ~Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern& other);

        /*------METHODE------*/
        AForm* makeForm(std::string name_form, std::string target);

        //Mehtode to make form
        AForm* make_shrubbery_creation_form(const std::string name_form, const std::string target);
        AForm* make_robotomy_request_form(const std::string name_form, const std::string target);
        AForm* make_presidential_pardon_form(const std::string name_form, const std::string target);
        
        AForm* get_type_form(std::string name_form, std::string target_name);
};

