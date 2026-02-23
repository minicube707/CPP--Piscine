/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 12:58:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void normal_test(std::string name, unsigned int grade)
{
    //area where an exception can occur
    try
    {
        Bureaucrat a = Bureaucrat(name, grade); 
        std::cout << a;
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
        Bureaucrat a = Bureaucrat(name, grade); 
        std::cout << a;
        a.increase_grade();
        std::cout << a;
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
        Bureaucrat a = Bureaucrat(name, grade); 
        std::cout << a;
        a.decrease_grade();
        std::cout << a;
    }
    //intercept an exception
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{   
    std::cout << "Normal test\n";
    normal_test("Charles de Gaulle", 0);
    normal_test("Ursula von der Leyen", 1);
    normal_test("Franklin D. Roosevelt", 150);
    normal_test("Olaf Scholz", 151);
    normal_test("Franklin D. Roosevelt", -1);

    std::cout << "\nIncraese test\n";
    increase_test("Charles de Gaulle", 0);
    increase_test("Ursula von der Leyen", 1);
    increase_test("Franklin D. Roosevelt", 150);
    increase_test("Olaf Scholz", 151);
    increase_test("Franklin D. Roosevelt", -1);

    std::cout << "\nDecraese test\n";
    decrease_test("Charles de Gaulle", 0);
    decrease_test("Ursula von der Leyen", 1);
    decrease_test("Franklin D. Roosevelt", 150);
    decrease_test("Olaf Scholz", 151);
    decrease_test("Franklin D. Roosevelt", -1);
}