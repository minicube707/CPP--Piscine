/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:39:41 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/27 15:35:20 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


Fixed calcul_area_triangle(Point const a, Point const b, Point const c)
{
    Point const vector_ab = b - a;
    Point const vector_ca = a - c;
    
    //Calcul coeficient b
    Fixed coef_b = dot_procduct(vector_ab, vector_ca);
    
    //Calcul coeficient a
    Point representation_paramretrique =  a - vector_ab;
    Point vector_cp = representation_paramretrique - c;
    Fixed coef_a = dot_procduct(vector_ab, vector_cp) - coef_b;
        
    //Calcul the unknow t
    Fixed unknow_t = (- coef_b) / coef_a;
    
    //Calculating the coordinates of the projection of C onto the line AB
    Point project_c =  a - (vector_ab * unknow_t);
    
    //Calculating base and height of triangle
    Fixed base = euclidean_distance(a, b);
    Fixed height = euclidean_distance(project_c, c);
    
    //Calculating area of triangle
    Fixed area_triangle = base * height / 2;

    return (area_triangle);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    /*===================*/
    /*=====Methode 1=====*/
    /*===================*/ 
    
    //Calcul area main triangle
    Fixed area_main_triangle = calcul_area_triangle(a, b, c);

    //Calcul triangle with the point
    Fixed area_triangle_abp = calcul_area_triangle(a, b, point);
    Fixed area_triangle_acp = calcul_area_triangle(a, c, point);
    Fixed area_triangle_bcp = calcul_area_triangle(b, c, point);

    std::cout << "The Area of the Main triange is " << area_main_triangle << "\n";

    std::cout << "The Area of the ABP triange is " << area_triangle_abp << "\n";
    std::cout << "The Area of the ACP triange is " << area_triangle_acp << "\n";
    std::cout << "The Area of the BCP triange is " << area_triangle_bcp << "\n";
    
    return (true);
}