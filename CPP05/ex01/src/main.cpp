/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 13:09:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

void normal_test(std::string name, unsigned int grade)
{
    //area where an exception can occur
    try
    {
        std::cout << "----------\n";
        Bureaucrat b = Bureaucrat(name, grade); 
        std::cout << b;
        
        Form f = Form("National Assembly dissolution Form", 10, 5);
        std::cout << f;
        b.signForm(f);
        std::cout << f;
        std::cout << "\n";
    }
    //intercept an exception
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

void increase_test(std::string name, unsigned int grade)
{
    //area where an exception can occur
    try
    {
        std::cout << "----------\n";
        Bureaucrat b = Bureaucrat(name, grade); 
        std::cout << b;
        b.increase_grade();
        std::cout << b;
        
        Form f = Form("National Assembly dissolution Form", 10, 5);
        std::cout << f;
        b.signForm(f);
        std::cout << f;
        std::cout << "\n";
    }
    //intercept an exception
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

void decrease_test(std::string name, unsigned int grade)
{
    //area where an exception can occur
    try
    {
        std::cout << "----------\n";
        Bureaucrat b = Bureaucrat(name, grade); 
        std::cout << b;
        b.decrease_grade();
        std::cout << b;
        
        Form f = Form("National Assembly dissolution Form", 10, 5);
        std::cout << f;
        b.signForm(f);
        std::cout << f;
        std::cout << "\n";
    }
    //intercept an exception
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{   
    std::cout << "\nNormal test\n";
    normal_test("Charles de Gaulle", 4);
    normal_test("Ursula von der Leyen", 5);
    normal_test("Franklin D. Roosevelt", 6);
    normal_test("Olaf Scholz", 9);
    normal_test("Franklin D. Roosevelt", 10 );
    normal_test("Barack Obama", 11 );

    std::cout << "\nIncraese test\n";
    increase_test("Charles de Gaulle", 4);
    increase_test("Ursula von der Leyen", 5);
    increase_test("Franklin D. Roosevelt", 6);
    increase_test("Olaf Scholz", 9);
    increase_test("Franklin D. Roosevelt", 10 );
    increase_test("Barack Obama", 11 );

    std::cout << "\nDecraese test\n";
    decrease_test("Charles de Gaulle", 4);
    decrease_test("Ursula von der Leyen", 5);
    decrease_test("Franklin D. Roosevelt", 6);
    decrease_test("Olaf Scholz", 9);
    decrease_test("Franklin D. Roosevelt", 10 );
    decrease_test("Barack Obama", 11 );
}