/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:39:41 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/26 17:44:08 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    /*===================*/
    /*=====Methode 1=====*/
    /*===================*/ 
       
    Point const vector_ab = b - a;
    Point const vector_ca = a - c;
    
    //Calcul coeficient b
    Fixed coef_b = dot_procduct(vector_ab, vector_ca);
    
    //Calcul coeficient a
    Point representation_paramretrique =  2 * a - b;
    Point vector_cp = representation_paramretrique - c;
    Fixed coef_a = dot_procduct(vector_ab, vector_cp) - coef_b;
    
    std::cout << "Coef A " << coef_a << std::endl;
    std::cout << "Coef B " << coef_b << std::endl;
    
    //Calcul the unknow t
    Fixed unknow_t = (- coef_b) / coef_a;
    std::cout << "t " << unknow_t << std::endl;
    
    //Calculating the coordinates of the projection of C onto the line AB
    Point project_c =  a - (vector_ab * unknow_t);
    
    std::cout << "Projection c " << project_c << std::endl;
    
    (void) point;
    return (true);
}