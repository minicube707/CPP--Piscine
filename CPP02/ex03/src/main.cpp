/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:57:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/27 15:19:01 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{   
    Point a (0, 2);
    Point b (1, 0);
    Point c (3, 2);
    Point p (2, 3);

    bsp(a, b, c, p);
    
    return 0;
}
