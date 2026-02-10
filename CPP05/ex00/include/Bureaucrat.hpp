/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:49 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 11:10:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
#include <stdexcept>

# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        unsigned int _grade;
        
    public:
        //Constructor
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(unsigned int grade);
        Bureaucrat(const std::string name, unsigned int grade);
        
        //Destructor, Copy Constructor, Copy Constructor
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat& other);

        /*--SETTER-&-GETTER--*/
        const std::string get_name(void) const;
        unsigned int get_grade(void) const;
        void set_grade(unsigned int grade);

        /*------METHODE------*/
        void check_grade(unsigned int grade);
        void increase_grade(void);
        void decrease_grade(void);

};

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif