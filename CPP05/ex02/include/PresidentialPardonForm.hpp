/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:31 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/19 15:46:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

class PresidentialPardonForm: public AForm
{
    private:
        //Const to initialize the value of the grades
        static const int _const_grade_sign = 25;
        static const int _const_grade_exec = 5;

        //Variable
        std::string _target;   
        
    public:
        //Constructor
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other); 
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
        /*------METHODE------*/
        void execute(Bureaucrat const & executor) const;
};


