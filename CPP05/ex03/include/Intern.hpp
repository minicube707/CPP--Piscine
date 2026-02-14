/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:44:22 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 18:29:05 by fmotte           ###   ########.fr       */
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

        AForm* make_shrubbery_creation_form();
        AForm* make_robotomy_request_form();
        AForm* make_presidential_pardon_form();
        
        void get_type_form(std::string name_form, std::string target_name);
};

