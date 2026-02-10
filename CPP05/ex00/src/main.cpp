/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:07:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 11:16:59 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{   
    //area where an exception can occur
    try
    {
        Bureaucrat a = Bureaucrat("Manu",0); 
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