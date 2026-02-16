/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:42:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/16 16:41:43 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <fstream>

# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"
# include "FormMissingPartException.hpp"
# include "FormNotSignedException.hpp"
# include "FormWrongNameException.hpp"

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        //Static Constant
        static const std::string _allowed_name_form[3];
        static const std::string _flag_wrong_name;
        
        //Constant
        const std::string _name;
        const unsigned int _grade_to_sign;
        const unsigned int _grade_to_exec;
        
        //Variable
        bool _is_signed;    
    
    protected:
        void check_execute(Bureaucrat const & executor) const;
        void check_grade(unsigned int grade);
        
    public:
        //Constructor
        AForm();
        AForm(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_exec);
        
        //Destructor, Copy Constructor, Copy Constructor
        virtual ~AForm() = 0;
        AForm(const AForm &other); 
        AForm& operator=(const AForm& other);

        /*--SETTER-&-GETTER--*/
        //Static getter
        static const std::string* get_allowed_name_form(void);
        static const std::string get_flag_wrong_name(void);
        
        //Getter
        const std::string get_name(void) const;
        unsigned int get_grade_to_sign(void) const;
        unsigned int get_grade_to_exec(void) const;
        bool get_state_sign(void) const;

        //Setter
        void set_state_sign(bool new_state);
        
        /*------METHODE------*/
        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;    //A purely virtual method

};

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const AForm& obj);

void check_name(std::string name_form, std::string target_name);

#endif