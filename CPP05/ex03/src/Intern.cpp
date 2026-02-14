/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:44:24 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 18:28:44 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

//Constructor
Intern::Intern(){}


//Destructor, Copy Constructor, Copy Constructor
Intern::~Intern() {}
Intern::Intern(const Intern &other) {(void) other;} //Useless Nothing to to pass on
Intern& Intern::operator=(const Intern& other) {(void) other; return (*this);} //Useless Nothing to to pass on

/*------METHODE------*/
AForm* Intern::makeForm(std::string name_form, std::string target_name)
{
    try
    {
        check_name(name_form, target_name);
        std::cout << "Intern creates " << name_form << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout <<"Iterim couldn't create a Form  because " << e.what() << '\n';
    }
}

AForm* Intern::make_shrubbery_creation_form(){return new ShrubberyCreationForm();}
AForm* Intern::make_robotomy_request_form(){ return new RobotomyRequestForm();}
AForm* Intern::make_presidential_pardon_form(){ return new PresidentialPardonForm();}

void Intern::get_type_form(std::string name_form, std::string target_name)
{
    //Same technic from CPP01/ex05
    std::string lis_form_str[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
}