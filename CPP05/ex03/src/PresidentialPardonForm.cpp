/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:17:32 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 14:16:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

//Constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", grade_sign, grade_exec), _target("Spider-Man") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("Presidential Pardon Form", grade_sign, grade_exec), _target(target) {}

//Destructor, Copy Constructor, Copy Constructor
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm("Presidential Pardon Form", grade_sign, grade_exec), _target(other._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        _target = other._target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    //Check the condition to execute the form
    check_execute(executor);
    
    //Form execute
    std::cout << _target << " has been pardonned by Zaphod Beeblerox\n";
}