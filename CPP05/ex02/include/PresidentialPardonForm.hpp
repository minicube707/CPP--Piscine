/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:31 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 17:40:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

#pragma once

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
        
    public:
        //Constructor
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);

        //Destructor, Copy Constructor, Copy Constructor
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other); 
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

};


