/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 15:06:14 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{   
    //area where an exception can occur
    try
    {
        Bureaucrat b = Bureaucrat("Manu", 4); 
        std::cout << b;
        b.decrease_grade();
        std::cout << b;
        
        std::cout << "\n";
        Form f = Form("National Assembly dissolution Form", 10, 5);
        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }
    //intercept an exception
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
}