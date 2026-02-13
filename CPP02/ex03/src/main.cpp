/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:57:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 18:07:43 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{   
    bool answer;
    
    //=============================
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (1, 1)
    //True
    
    Point a (0, 2);
    Point b (1, 0);
    Point c (3, 2);
    Point p (1, 1);
    
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

       
    //=============================    
    //Out of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (0, 1)
    //False

    p = Point (0, 1);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";


    //============================= 
    //Out of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (1.5, 2.5)
    //False

    p = Point (1.5, 2.5);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

    
    //=============================
    //Out of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (2, 0.5)
    //False

    p = Point (2, 0.5);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    //=============================
    //On one straight of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (2.2, 1.2)
    //False on straight BC

    p = Point (2.2, 1.2);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    
    //=============================
    //On one straight of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (0.6, 2)
    //False on straight AC
    
    p = Point (0.6, 2);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    //=============================
    //On one straight of the triangle
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (0.8, 0.4)
    //False on straight AB

    p = Point (0.8, 0.4);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";


    //=============================
    //Test precision
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (1.264, 0.264)
    //False on straight BC

    p = Point (1.264, 0.264);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    //=============================
    //Test precision
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (0.535, 2)
    //False on straight AC

    p = Point (0.535, 2);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    //=============================
    //Test precision
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (0.9253,0.1494)
    //False on straight AC

    p = Point (0.9253,0.1494);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

        
    //=============================
    //Test precision
    //A (0, 2)
    //B (1, 0)
    //C (3, 2)
    //P (1, 1.9995)
    //True 

    p = Point (1, 1.995);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

    //=============================
    //Test Point are same coordonnate
    //A (0, 2)
    //B (0, 0)
    //C (3, 2)
    //P (1.17,1.97)
    //True 

    b = Point (0, 0);
    p = Point (0, 0);
    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";
}