/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:42:54 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 15:02:10 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

//Constructor
Form::Form(): _name("Important form"), _is_signed(false), _grade_to_sign(1), _grade_to_exec(1) {}
Form::Form(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_exec):
_name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    check_grade(grade_to_sign);
    check_grade(grade_to_exec);
}

//Destructor, Copy Constructor, Copy Constructor
Form::~Form() {}
Form::Form(const Form &other):
_name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec)
{
    check_grade(other._grade_to_sign);
    check_grade(other._grade_to_exec);
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    return (*this);
}

/*--SETTER-&-GETTER--*/
const std::string Form::get_name(void) const {return _name;}
unsigned int Form::get_grade_to_sign(void) const {return _grade_to_sign;}
unsigned int Form::get_grade_to_exec(void) const {return _grade_to_exec;}
bool Form::get_state_sign(void) const {return _is_signed;}

void Form::set_state_sign(bool new_state) {_is_signed = new_state;}
        
/*------METHODE------*/
void Form::beSigned(const Bureaucrat& b)
{
    if (_grade_to_sign < b.get_grade())
        throw GradeTooLowException();
    _is_signed = true;
}

void Form::check_grade(unsigned int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
        
    if (grade > 150)
        throw GradeTooLowException();
}

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Form& obj)
{os << obj.get_name() << " in state " << obj.get_state_sign() << " must be sign with a grade " << obj.get_grade_to_sign() << \
    " and must be execute with a grade " << obj.get_grade_to_exec() << "\n";
    return os;
}