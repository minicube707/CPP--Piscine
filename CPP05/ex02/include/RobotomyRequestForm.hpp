/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:38:09 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 17:38:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
        
    public:
        //Constructor
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other); 
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

};