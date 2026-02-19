/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:17:32 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/19 15:46:38 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

//Constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", _const_grade_sign, _const_grade_exec), _target("WALL-E") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("Robotomy Request Form", _const_grade_sign, _const_grade_exec), _target(target) {}

//Destructor, Copy Constructor, Copy Constructor
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("Robotomy Request Form", _const_grade_sign, _const_grade_exec), _target(other._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        _target = other._target;
    return (*this);
}

/*------METHODE------*/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{   
    //Check the condition to execute the form
    checkExecute(executor);

    //Form execute
    if (std::rand() % 2 == 0) 
        std::cout << _target << " has been robotomized successfully\n"; 
    else 
        std::cout << _target << " robotomized fail ! He was already not that smart anyway\n";
}