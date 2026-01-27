/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:57:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/27 18:37:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{   
    bool answer;
    
    Point a (0, 2);
    Point b (1, 0);
    Point c (3, 2);
    Point p (1, 1);

    answer = bsp(a, b, c, p);
    
    if (answer)
        std::cout << "\nThe function return " << GREEN << "true" << "\n";
    else
        std::cout << "\nThe function return " << RED << "false" << "\n";
    return 0;
}
