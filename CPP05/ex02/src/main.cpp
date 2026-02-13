/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 18:42:19 by fmotte           ###   ########.fr       */
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
    
    /*====================
    ShrubberyCreationForm
    ====================*/
    std::cout << "\n\nTESTS ShrubberyCreationForm\n";
    
    //Create three Bureaucrat
    Bureaucrat low_gardener("Low Gardener");
    Bureaucrat middle_gardener("Middle Gardener", 140);
    Bureaucrat hight_gardener("Hight Gardener", 100);
    
    std::cout << "\n";
    std::cout << low_gardener;
    std::cout << middle_gardener;
    std::cout << hight_gardener;
    
    //Create three ShrubberyCreationForm
    ShrubberyCreationForm form_shrub_planter1 = ShrubberyCreationForm("Shrub Planter1");
    ShrubberyCreationForm form_shrub_planter2 = ShrubberyCreationForm("Shrub Planter2");
    ShrubberyCreationForm form_shrub_planter3 = ShrubberyCreationForm("Shrub Planter3");
    
    std::cout << "\n";
    std::cout << form_shrub_planter1;
    std::cout << form_shrub_planter2;
    std::cout << form_shrub_planter3;
    
    //Try to sign ShrubberyCreationForm
    std::cout << "\n";
    low_gardener.signForm(form_shrub_planter1);
    middle_gardener.signForm(form_shrub_planter2);
    hight_gardener.signForm(form_shrub_planter3);

    std::cout << "\n";
    std::cout << form_shrub_planter1;
    std::cout << form_shrub_planter2;
    std::cout << form_shrub_planter3;

    //Try to execute ShrubberyCreationForm
    std::cout << "\n";
    low_gardener.executeForm(form_shrub_planter1);
    middle_gardener.executeForm(form_shrub_planter2);
    hight_gardener.executeForm(form_shrub_planter3);


    /*====================
    RobotomyRequestForm
    ====================*/
    std::cout << "\n\nTESTS RobotomyRequestForm\n";
    
    //Create three Bureaucrat
    Bureaucrat low_engineer("Low Engineer", 100);
    Bureaucrat middle_engineer("Middle Engineer", 50);
    Bureaucrat hight_engineer("Tony Stark", 30);
    
    std::cout << "\n";
    std::cout << low_engineer;
    std::cout << middle_engineer;
    std::cout << hight_engineer;
    
    //Create three RobotomyRequestForm
    RobotomyRequestForm robot_request_form1 = RobotomyRequestForm("Robot Form1");
    RobotomyRequestForm robot_request_form2 = RobotomyRequestForm("Robot Form2");
    RobotomyRequestForm robot_request_form3 = RobotomyRequestForm("Robot Form3");
    
    std::cout << "\n";
    std::cout << robot_request_form1;
    std::cout << robot_request_form2;
    std::cout << robot_request_form3;
    
    //Try to sign RobotomyRequestForm
    std::cout << "\n";
    low_engineer.signForm(robot_request_form1);
    middle_engineer.signForm(robot_request_form2);
    hight_engineer.signForm(robot_request_form3);

    std::cout << "\n";
    std::cout << robot_request_form1;
    std::cout << robot_request_form2;
    std::cout << robot_request_form3;

    //Try to execute RobotomyRequestForm
    std::cout << "\n";
    low_engineer.executeForm(robot_request_form1);
    middle_gardener.executeForm(robot_request_form2);
    
    std::cout << "\n";
    hight_engineer.executeForm(robot_request_form3);
    hight_engineer.executeForm(robot_request_form3);
    hight_engineer.executeForm(robot_request_form3);
    hight_engineer.executeForm(robot_request_form3);


    /*====================
    PresidentialPardonForm
    ====================*/
    std::cout << "\n\nTESTS PresidentialPardonForm\n";
    
    //Create three Bureaucrat
    Bureaucrat little_dictor("Fidel Castro", 50);
    Bureaucrat french_president("Emmanuelle Macron", 10);
    Bureaucrat potus ("Barack Obama", 1);
    
    std::cout << "\n";
    std::cout << little_dictor;
    std::cout << french_president;
    std::cout << potus;
    
    //Create three PresidentialPardonForm
    PresidentialPardonForm presidential_pardon_form1 = PresidentialPardonForm("Lebron James");
    PresidentialPardonForm presidential_pardon_form2 = PresidentialPardonForm("Stephen Curry");
    PresidentialPardonForm presidential_pardon_form3 = PresidentialPardonForm("Victor Wembanyama");
    
    std::cout << "\n";
    std::cout << presidential_pardon_form1;
    std::cout << presidential_pardon_form2;
    std::cout << presidential_pardon_form3;
    
    //Try to sign PresidentialPardonForm
    std::cout << "\n";
    little_dictor.signForm(presidential_pardon_form1);
    french_president.signForm(presidential_pardon_form2);
    potus.signForm(presidential_pardon_form3);

    std::cout << "\n";
    std::cout << presidential_pardon_form1;
    std::cout << presidential_pardon_form2;
    std::cout << presidential_pardon_form3;

    //Try to execute PresidentialPardonForm
    std::cout << "\n";
    little_dictor.executeForm(presidential_pardon_form1);
    french_president.executeForm(presidential_pardon_form2);
    potus.executeForm(presidential_pardon_form3);
}