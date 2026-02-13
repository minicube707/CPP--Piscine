/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:38:09 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 18:14:00 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

# include <cstdlib>
# include <ctime>

class RobotomyRequestForm: public AForm
{
    private:
        //Const to initialize the value of the grades
        static const int grade_sign = 72;
        static const int grade_exec = 45;
        
        //Variable
        std::string _target;
        
    public:
        //Constructor
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        /*------METHODE------*/
        void execute(Bureaucrat const & executor) const;
};