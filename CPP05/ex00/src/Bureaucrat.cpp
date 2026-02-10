/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:53 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 11:10:37 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

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

/*--SETTER-&-GETTER--*/
const std::string Bureaucrat::get_name(void) const {return _name;}
unsigned int Bureaucrat::get_grade(void) const {return _grade;}
void Bureaucrat::set_grade(unsigned int grade) {check_grade(grade);}

/*------METHODE------*/
void Bureaucrat::check_grade(unsigned int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
        
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

void Bureaucrat::increase_grade(void){check_grade(_grade - 1);}
void Bureaucrat::decrease_grade(void){check_grade(_grade + 1);}

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){os << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << "\n"; return (os);}