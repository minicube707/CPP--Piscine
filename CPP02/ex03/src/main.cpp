/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:57:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/14 16:55:57 by fmotte           ###   ########.fr       */
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
    Point p1 (1, 1);
    
    answer = bsp(a, b, c, p1);
    
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

    Point p2 = Point (0, 1);
    answer = bsp(a, b, c, p2);
    
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

    Point p3 = Point (1.5, 2.5);
    answer = bsp(a, b, c, p3);
    
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

    Point p4 = Point (2, 0.5);
    answer = bsp(a, b, c, p4);
    
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

    Point p5 = Point (2.2, 1.2);
    answer = bsp(a, b, c, p5);
    
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
    
    Point p6 = Point (0.6, 2);
    answer = bsp(a, b, c, p6);
    
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

    Point p7 = Point (0.8, 0.4);
    answer = bsp(a, b, c, p7);
    
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

    Point p8 = Point (1.264, 0.264);
    answer = bsp(a, b, c, p8);
    
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

    Point p9 = Point (0.535, 2);
    answer = bsp(a, b, c, p9);
    
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
    //False on straight AB

    Point p10 = Point (0.9253,0.1494);
    answer = bsp(a, b, c, p10);
    
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

    Point p11 = Point (1, 1.995);
    answer = bsp(a, b, c, p11);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";

    //=============================
    //Test Point are same coordonnate
    //A (0, 2)
    //B (0, 0)
    //C (3, 2)
    //P (0, 0)
    //True 

    Point b2 = Point (0, 0);
    Point p12 = Point (0, 0);
    answer = bsp(a, b2, c, p12);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << RESET << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << RESET << "\n";
}