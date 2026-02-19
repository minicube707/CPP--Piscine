/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/19 16:01:47 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
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
    std::cout << "\nCreate three Bureaucrat\n";
    Bureaucrat low_gardener("Low Gardener");
    Bureaucrat middle_gardener("Middle Gardener", 140);
    Bureaucrat hight_gardener("Hight Gardener", 100);
    
    std::cout << low_gardener;
    std::cout << middle_gardener;
    std::cout << hight_gardener;
    
    //Create Intern
    std::cout << "\nCreate Intern\n";
    Intern nobody;
    
    //Create three ShrubberyCreationForm Correct
    std::cout << "\nCreate three ShrubberyCreationForm Correct\n";
    AForm *form_shrub_planter1 = nobody.makeForm("ShrubberyCreationForm", "Shrub Planter1");
    AForm *form_shrub_planter2 = nobody.makeForm("ShrubberyCreationForm", "Shrub Planter2");
    AForm *form_shrub_planter3 = nobody.makeForm("ShrubberyCreationForm", "Shrub Planter3");
    
    std::cout << "\nCreate three ShrubberyCreationForm Wrong\n";
    AForm *form_shrub_planter4 = nobody.makeForm("Unlimited Ice Cream Form", "Shrub Planter4");
    AForm *form_shrub_planter5 = nobody.makeForm("", "Shrub Planter5");
    AForm *form_shrub_planter6 = nobody.makeForm("ShrubberyCreationForm", "");
    
    
    //Display three ShrubberyCreationForm
    std::cout << "\nDisplay three ShrubberyCreationForm Correct\n";
    std::cout << *form_shrub_planter1;
    std::cout << *form_shrub_planter2;
    std::cout << *form_shrub_planter3;
    
    std::cout << "\nDisplay three ShrubberyCreationForm Wrong\n";
    std::cout << *form_shrub_planter4;
    std::cout << *form_shrub_planter5;
    std::cout << *form_shrub_planter6;
    
    
    //Try to sign ShrubberyCreationForm
    std::cout << "\nTry to sign ShrubberyCreationForm Correct\n";
    low_gardener.signForm(*form_shrub_planter1);
    middle_gardener.signForm(*form_shrub_planter2);
    hight_gardener.signForm(*form_shrub_planter3);
    
    std::cout << "\nTry to sign ShrubberyCreationForm Wrong\n";
    low_gardener.signForm(*form_shrub_planter4);
    low_gardener.signForm(*form_shrub_planter5);
    low_gardener.signForm(*form_shrub_planter6);
    
    
    //Display three ShrubberyCreationForm
    std::cout << "\nDisplay three ShrubberyCreationForm Correct\n";
    std::cout << *form_shrub_planter1;
    std::cout << *form_shrub_planter2;
    std::cout << *form_shrub_planter3;
    
    std::cout << "\nDisplay three ShrubberyCreationForm Wrong\n";
    std::cout << *form_shrub_planter4;
    std::cout << *form_shrub_planter5;
    std::cout << *form_shrub_planter6;
    
    
    //Try to execute ShrubberyCreationForm
    std::cout << "\nTry to execute ShrubberyCreationForm Correct\n";
    low_gardener.executeForm(*form_shrub_planter1);
    middle_gardener.executeForm(*form_shrub_planter2);
    hight_gardener.executeForm(*form_shrub_planter3);
    
    std::cout << "\nTry to execute ShrubberyCreationForm Wrong\n";
    low_gardener.executeForm(*form_shrub_planter4);
    low_gardener.executeForm(*form_shrub_planter5);
    low_gardener.executeForm(*form_shrub_planter6);
    
    //Free AFORM*
    delete form_shrub_planter1;
    delete form_shrub_planter2;
    delete form_shrub_planter3;
    delete form_shrub_planter4;
    delete form_shrub_planter5;
    delete form_shrub_planter6;
    
    /*====================
    RobotomyRequestForm
    ====================*/
    
    std::cout << "\n\nTESTS RobotomyRequestForm\n";
    
    //Create three Bureaucrat
    std::cout << "\nCreate three Bureaucrat\n";
    Bureaucrat low_engineer("Low Engineer", 100);
    Bureaucrat middle_engineer("Middle Engineer", 50);
    Bureaucrat hight_engineer("Tony Stark", 30);
    
    std::cout << "\n";
    std::cout << low_engineer;
    std::cout << middle_engineer;
    std::cout << hight_engineer;
    
    //Create three RobotomyRequestForm
    std::cout << "\nCreate three RobotomyRequestForm Correct\n";
    AForm *robot_request_form1 = nobody.makeForm("RobotomyRequestForm", "Robot Form1");
    AForm *robot_request_form2 = nobody.makeForm("RobotomyRequestForm", "Robot Form2");
    AForm *robot_request_form3 = nobody.makeForm("RobotomyRequestForm", "Robot Form3");
    
    std::cout << "\nCreate three RobotomyRequestForm Wrong\n";
    AForm *robot_request_form4 = nobody.makeForm("Form to Request a Form", "Robot Form1");
    AForm *robot_request_form5 = nobody.makeForm("", "Robot Form2");
    AForm *robot_request_form6 = nobody.makeForm("RobotomyRequestForm", "");
    

    //Display three RobotomyRequestForm
    std::cout << "\nDisplay three RobotomyRequestForm Correct\n";
    std::cout << *robot_request_form1;
    std::cout << *robot_request_form2;
    std::cout << *robot_request_form3;
    
    std::cout << "\nDisplay three RobotomyRequestForm Wrong\n";
    std::cout << *robot_request_form4;
    std::cout << *robot_request_form5;
    std::cout << *robot_request_form6;
    
    
    //Try to sign RobotomyRequestForm
    std::cout << "\nTry to sign RobotomyRequestForm Correct\n";
    low_engineer.signForm(*robot_request_form1);
    middle_engineer.signForm(*robot_request_form2);
    hight_engineer.signForm(*robot_request_form3);

    std::cout << "\nTry to sign RobotomyRequestForm Wrong\n";
    low_engineer.signForm(*robot_request_form4);
    middle_engineer.signForm(*robot_request_form5);
    hight_engineer.signForm(*robot_request_form6);
    

    //Display three RobotomyRequestForm
    std::cout << "\nDisplay three RobotomyRequestForm Correct\n";
    std::cout << *robot_request_form1;
    std::cout << *robot_request_form2;
    std::cout << *robot_request_form3;
    
    std::cout << "\nDisplay three RobotomyRequestForm Wrong\n";
    std::cout << *robot_request_form4;
    std::cout << *robot_request_form5;
    std::cout << *robot_request_form6;

    
    //Try to execute RobotomyRequestForm
    std::cout << "\nTry to execute RobotomyRequestForm Correct\n";
    low_engineer.executeForm(*robot_request_form1);
    middle_gardener.executeForm(*robot_request_form2);
    
    std::cout << "\n";
    hight_engineer.executeForm(*robot_request_form3);
    hight_engineer.executeForm(*robot_request_form3);
    hight_engineer.executeForm(*robot_request_form3);
    hight_engineer.executeForm(*robot_request_form3);

    std::cout << "\nTry to execute RobotomyRequestForm Wrong\n";
    low_engineer.executeForm(*robot_request_form4);
    middle_engineer.executeForm(*robot_request_form5);
    hight_engineer.executeForm(*robot_request_form6);
    
    //Free AFORM*
    delete robot_request_form1;
    delete robot_request_form2;
    delete robot_request_form3;
    delete robot_request_form4;
    delete robot_request_form5;
    delete robot_request_form6;
    
    /*====================
    PresidentialPardonForm
    ====================*/

    std::cout << "\n\nTESTS PresidentialPardonForm\n";
    
    //Create three Bureaucrat
    Bureaucrat little_dictator("Fidel Castro", 50);
    Bureaucrat french_president("Emmanuelle Macron", 10);
    Bureaucrat potus ("Barack Obama", 1);
    
    std::cout << "\n";
    std::cout << little_dictator;
    std::cout << french_president;
    std::cout << potus;
    
    
    //Create three PresidentialPardonForm
    std::cout << "\nCreate three PresidentialPardonForm Correct\n";
    AForm *presidential_pardon_form1 = nobody.makeForm("PresidentialPardonForm", "Lebron James");
    AForm *presidential_pardon_form2 = nobody.makeForm("PresidentialPardonForm", "Stephen Curry");
    AForm *presidential_pardon_form3 = nobody.makeForm("PresidentialPardonForm", "Victor Wembanyama");
    
    std::cout << "\nCreate three PresidentialPardonForm Wrong\n";
    AForm *presidential_pardon_form4 = nobody.makeForm("Form to Claim a Lost Form", "James Harder");
    AForm *presidential_pardon_form5 = nobody.makeForm("", "Michael Jordan");
    AForm *presidential_pardon_form6 = nobody.makeForm("PresidentialPardonForm", "");
    
    
    //Display three PresidentialPardonForm
    std::cout << "\nDisplay three PresidentialPardonForm Correct\n";
    std::cout << *presidential_pardon_form1;
    std::cout << *presidential_pardon_form2;
    std::cout << *presidential_pardon_form3;
    
    std::cout << "\nDisplay three PresidentialPardonForm Wrong\n";
    std::cout << *presidential_pardon_form4;
    std::cout << *presidential_pardon_form5;
    std::cout << *presidential_pardon_form6;
    
    
    //Try to sign PresidentialPardonForm
    std::cout << "\nTry to sign PresidentialPardonForm Correct\n";
    little_dictator.signForm(*presidential_pardon_form1);
    french_president.signForm(*presidential_pardon_form2);
    potus.signForm(*presidential_pardon_form3);

    std::cout << "\nTry to sign PresidentialPardonForm Wrong\n";
    little_dictator.signForm(*presidential_pardon_form4);
    french_president.signForm(*presidential_pardon_form5);
    potus.signForm(*presidential_pardon_form6);
    
    
    //Display three PresidentialPardonForm
    std::cout << "\nDisplay three PresidentialPardonForm Correct\n";
    std::cout << *presidential_pardon_form1;
    std::cout << *presidential_pardon_form2;
    std::cout << *presidential_pardon_form3;
    
    std::cout << "\nDisplay three PresidentialPardonForm Wrong\n";
    std::cout << *presidential_pardon_form4;
    std::cout << *presidential_pardon_form5;
    std::cout << *presidential_pardon_form6;

    
    //Try to execute PresidentialPardonForm
    std::cout << "\nTry to execute PresidentialPardonForm Correct\n";
    little_dictator.executeForm(*presidential_pardon_form1);
    french_president.executeForm(*presidential_pardon_form2);
    potus.executeForm(*presidential_pardon_form3);
    
    std::cout << "\nTry to execute PresidentialPardonForm Wrong\n";
    little_dictator.executeForm(*presidential_pardon_form4);
    french_president.executeForm(*presidential_pardon_form5);
    potus.executeForm(*presidential_pardon_form6);
    
    delete presidential_pardon_form1;
    delete presidential_pardon_form2;
    delete presidential_pardon_form3;
    delete presidential_pardon_form4;
    delete presidential_pardon_form5;
    delete presidential_pardon_form6;
}