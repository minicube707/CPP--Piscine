/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:42:54 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 17:00:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

/* ************************************************************************** */
/*                          STATIC CONSTANT                                   */
/* ************************************************************************** */

const std::string AForm::_allowed_name_form[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

/* ************************************************************************** */
/*                             CANONICAL FORM                                 */
/* ************************************************************************** */

//Constructor
AForm::AForm(): _name("Important form"), _grade_to_sign(150), _grade_to_exec(150), _is_signed(false) {}
AForm::AForm(const std::string name, const unsigned int grade_to_sign, const unsigned int grade_to_exec):
_name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _is_signed(false)
{
    check_grade(grade_to_sign);
    check_grade(grade_to_exec);
}

//Destructor, Copy Constructor, Copy Constructor
AForm::~AForm() {}
AForm::AForm(const AForm &other):
_name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec), _is_signed(other._is_signed)
{
    check_grade(other._grade_to_sign);
    check_grade(other._grade_to_exec);
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    return (*this);
}


/* ************************************************************************** */
/*                            GETTER & SETTER                                 */
/* ************************************************************************** */

//Static getter
const std::string* AForm::get_allowed_name_form(void) {return _allowed_name_form;}

//Getter
const std::string AForm::get_name(void) const {return _name;}
unsigned int AForm::get_grade_to_sign(void) const {return _grade_to_sign;}
unsigned int AForm::get_grade_to_exec(void) const {return _grade_to_exec;}
bool AForm::get_state_sign(void) const {return _is_signed;}

//Setter
void AForm::set_state_sign(bool new_state) {_is_signed = new_state;}
        

/* ************************************************************************** */
/*                                 PROTECTED                                  */
/* ************************************************************************** */

//Check the grade at initialization
void AForm::check_grade(unsigned int grade) 
{
    //If grade too Hight
    if (grade < 1)
        throw AForm::GradeTooHighException();
    
    //If grade too Low
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

//Check the Form before to be sign
void AForm::check_execute(Bureaucrat const & executor) const
{
    //If the Form is signed
    if (get_state_sign() == false)
        throw AForm::FormNotSignedException();
        
    //If the grade of the Form is greater than the Bureaucrat
    if (executor.get_grade() > get_grade_to_exec())
        throw AForm::GradeTooLowException();
}

/* ************************************************************************** */
/*                                  PUBLIC                                    */
/* ************************************************************************** */

void AForm::beSigned(const Bureaucrat& b)
{

    //Check if the grade is greater than
    if (_grade_to_sign < b.get_grade())
        throw AForm::GradeTooLowException();
    
    //Else sign the Form
    _is_signed = true;
}


/* ************************************************************************** */
/*                                FUNCTION                                    */
/* ************************************************************************** */

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const AForm* obj)
{   
    //Check if the name is correct
    if (obj == 0)
        os << "Empty Form\n";
    

    //Else print the information
    else
    {
        os << obj->get_name() << " in state " << obj->get_state_sign() << " requires a signing grade of " << obj->get_grade_to_sign() << \
        " and an execution grade of " << obj->get_grade_to_exec() << "\n";
    }
    return os;
}

//Check the name and the target of the Form
void check_name(std::string name_form, std::string target_name)
{
    //If the Form Doesn't have a name
    if (name_form == "")
        throw FormMissingPartException("Name Form");
    
    //If the Target Doesn't have a name
    if (target_name == "")
        throw FormMissingPartException("Target Name");

    const std::string* tmp_allowed_name_form = AForm::get_allowed_name_form();
    for (int i = 0; i < 3; i++)
    {
        //If the name Form is allowed do nothing
        if (name_form == tmp_allowed_name_form[i])
            return;
    }
    //Else raise Execption
    throw FormWrongNameException();
}