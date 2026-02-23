/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:44:24 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 16:56:07 by fmotte           ###   ########.fr       */
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
        return get_type_form(name_form, target_name);
    }
    catch(const FormMissingPartException& e)
    {
        std::cout <<"Iterim couldn't create a Form  because " << e.what() << '\n';
        
        //If a execption is raise create an empty form
        return 0;
    }
    catch(const FormWrongNameException& e)
    {
        std::cout <<"Iterim couldn't create a Form  because " << e.what() << '\n';

        //If a execption is raise create an empty form
        return 0;
    }
}

//Mehtode to make form
AForm* Intern::make_shrubbery_creation_form(const std::string name_form, const std::string target){return new ShrubberyCreationForm(name_form, target);}
AForm* Intern::make_robotomy_request_form(const std::string name_form, const std::string target){ return new RobotomyRequestForm(name_form, target);}
AForm* Intern::make_presidential_pardon_form(const std::string name_form, const std::string target){ return new PresidentialPardonForm(name_form, target);}

AForm*  Intern::get_type_form(std::string name_form, std::string target_name)
{
    //Same technic from CPP01/ex05
    std::string lis_form_str[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    
    // Array of Intern member function pointers used to create different forms
    // Each element is a pointer to a member function of Intern
    // that takes two const std::string, and returns an AForm*
    AForm* (Intern::*lis_form_func[3])(const std::string name_form, const std::string target) = 
    {
        // Store the addresses of the class Intern member functions
        &Intern::make_shrubbery_creation_form, 
        &Intern::make_robotomy_request_form, 
        &Intern::make_presidential_pardon_form
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (name_form == lis_form_str[i])
            // Call the member function at index i on the current instance
            return (this->*lis_form_func[i])(name_form, target_name);
    }
    //If a execption is raise create an empty form
    return 0;
}