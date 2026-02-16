/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:53 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/16 15:11:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                             CANONICAL FORM                                 */
/* ************************************************************************** */

//Constructor
Bureaucrat::Bureaucrat(): _name("Nobody"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150) {}
Bureaucrat::Bureaucrat(unsigned int grade): _name("Nobody") {check_grade(grade);}
Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name) {check_grade(grade);}

//Destructor, Copy Constructor, Copy Constructor
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return (*this);
}


/* ************************************************************************** */
/*                            GETTER & SETTER                                 */
/* ************************************************************************** */

const std::string Bureaucrat::get_name(void) const {return _name;}
unsigned int Bureaucrat::get_grade(void) const {return _grade;}
void Bureaucrat::set_grade(unsigned int grade) {check_grade(grade);}


/* ************************************************************************** */
/*                                  PUBLIC                                    */
/* ************************************************************************** */

void Bureaucrat::signForm(AForm& f)
{   
    try
    {
       f.beSigned(*this);
       std::cout << _name << " signed " << f.get_name() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << f.get_name() << " because " << e.what() << '\n';
    }
    

}

void Bureaucrat::increase_grade(void){check_grade(_grade - 1);}
void Bureaucrat::decrease_grade(void){check_grade(_grade + 1);}


void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.get_name() << '\n';
    }
    catch(const std::exception& e)
    {
       std::cout << _name << " couldn't execute " << form.get_name() << " because " << e.what() << '\n';
    }
    
}

//Check the grade at initialization
void Bureaucrat::check_grade(unsigned int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
        
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}


/* ************************************************************************** */
/*                                FUNCTION                                    */
/* ************************************************************************** */

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){os << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << "\n"; return (os);}