/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/11 16:06:09 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{   
    //Initiaze pseudo-random number generator using the current time since the 1er janvier 1970 (timestamp Unix)
    //Need for the class RobotomyRequestForm
    std::srand(std::time(0));
    
    PresidentialPardonForm s;
    Bureaucrat b("Bureau", 1);
    b.signForm(s);
    
    b.executeForm(s);
    std::cout << s;
}