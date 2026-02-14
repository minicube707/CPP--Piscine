/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:17:32 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 14:16:39 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

//Constructor
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", grade_sign, grade_exec), _target("Home") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("Shrubbery Creation Form", grade_sign, grade_exec), _target(target) {}

//Destructor, Copy Constructor, Copy Constructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("Shrubbery Creation Form", grade_sign, grade_exec), _target(other._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        _target = other._target;
    return (*this);
}

/*------METHODE------*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    //Check the condition to execute the form
    check_execute(executor);
    
    //Form execute
    /*Edit filename output*/
    std::string filename_repalce = _target;
    filename_repalce.append("_shrubbery");
    
    //Writting
    std::ofstream w(filename_repalce.c_str());
    if (w.is_open())
        w << ASCII_TREE;
    w.close();
}