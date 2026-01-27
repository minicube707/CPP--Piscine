/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:39:41 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/27 17:45:22 by fmotte           ###   ########.fr       */
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

/*===================*/
/*=====Methode 1=====*/
/*===================*/ 
bool methode_1(Point const a, Point const b, Point const c, Point const point)
{
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

    Fixed sum_area = area_triangle_abp + area_triangle_acp + area_triangle_bcp;

    if (roundf(sum_area.toFloat()) > roundf(area_main_triangle.toFloat()))
    {
        std::cout << "\nThe sum of area of the sub-triangne is greater than to the main triangle.\nThe point is not in the triangle\n";
        std::cout << "Sum area equal + area main triangle: " << sum_area << " > " << area_main_triangle << "\n";
        std::cout << "Return false\n";
        return (false);
    }
    
    if (area_triangle_abp == 0)
    {
        std::cout << "\nThe area of the triangle ABP is null. That means the point P is on the straight AB\n";
        std::cout << "Return false\n";
        return (false);
    }
    if (area_triangle_acp == 0)
    {
        std::cout << "\nThe area of the triangle ACP is null. That means the point P is on the straight AC\n";
        std::cout << "Return false\n";
        return (false);
    }
        if (area_triangle_bcp == 0)
    {
        std::cout << "\nThe area of the triangle BCP is null. That means the point P is on the straight BC\n";
        std::cout << "Return false\n";
        return (false);
    }
    
    std::cout << "\nThe sum of area of the sub-triangne is equal to the main triangle.\nThe point is in the triangle\n";
    std::cout << "Any of the area of the sub-triangle are null. That means the point P is not on the edge of the triangle\n";
    std::cout << "Return true\n";
    return (true);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    /*=====Methode 1=====*/
    methode_1(a, b, c, point);

    return (true);
}