/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:39:41 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 17:56:16 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

# include <string>

/*===================*/
/*=====Methode 1=====*/
/*===================*/
Fixed calcul_area_triangle(Point const point_a, Point const point_b, Point const point_c)
{
    Point const vector_ab = get_vecteur(point_a, point_b);
    Point const vector_ca = get_vecteur(point_c, point_a);
    
    //Calcul coeficient b
    Fixed coef_b = dot_procduct(vector_ab, vector_ca);
    
    //Calcul coeficient a
    Point representation_paramretrique =  point_a - vector_ab;
    Point vector_cp = get_vecteur(point_c, representation_paramretrique);
    Fixed coef_a = dot_procduct(vector_ab, vector_cp) - coef_b;
        
    //Calcul the unknow t
    Fixed unknow_t = - coef_b / coef_a;
    
    //Calculating the coordinates of the projection of C into the line AB
    Point project_c =  point_a - (vector_ab * unknow_t);
    
    //Calculating base and height of triangle
    Fixed base = euclidean_distance(point_a, point_b);
    Fixed height = euclidean_distance(project_c, point_c);
    
    //Calculating area of triangle
    Fixed area_triangle = base * height / 2;

    return (area_triangle);
}
 
bool methode_1(Point const point_a, Point const point_b, Point const point_c, Point const point)
{
    //Calcul area main triangle
    Fixed area_main_triangle = calcul_area_triangle(point_a, point_b, point_c);

    //Calcul triangle with the point
    Fixed area_triangle_abp = calcul_area_triangle(point_a, point_b, point);
    Fixed area_triangle_acp = calcul_area_triangle(point_a, point_c, point);
    Fixed area_triangle_bcp = calcul_area_triangle(point_b, point_c, point);

    std::cout << "The Area of the Main triange is " << area_main_triangle << "\n";

    std::cout << "The Area of the ABP triange is " << area_triangle_abp << "\n";
    std::cout << "The Area of the ACP triange is " << area_triangle_acp << "\n";
    std::cout << "The Area of the BCP triange is " << area_triangle_bcp << "\n";

    Fixed sum_area = area_triangle_abp + area_triangle_acp + area_triangle_bcp;

    if (roundf(sum_area.toFloat()) > roundf(area_main_triangle.toFloat()))
    {
        std::cout << "\nThe sum of area of the sub-triangle is greater than to the main triangle.\nThe point is not in the triangle\n";
        std::cout << "Sum area equal + area main triangle: " << sum_area << " > " << area_main_triangle << "\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    
    if (area_triangle_abp == 0)
    {
        std::cout << "\nThe area of the triangle ABP is null. That means the point P is on the straight AB\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    if (area_triangle_acp == 0)
    {
        std::cout << "\nThe area of the triangle ACP is null. That means the point P is on the straight AC\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
        if (area_triangle_bcp == 0)
    {
        std::cout << "\nThe area of the triangle BCP is null. That means the point P is on the straight BC\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    
    std::cout << "\nThe sum of area of the sub-triangle is equal to the main triangle.\nThe point is in the triangle\n";
    std::cout << "Sum area equal + area main triangle: " << sum_area << " == " << area_main_triangle << "\n";
    std::cout << "Any area of the sub-triangle aren't null. That means the point P is not on the edge of the triangle\n";
    std::cout << "Return " << GREEN << "true" << RESET << "\n";
    return (true);
}


/*===================*/
/*=====Methode 2=====*/
/*===================*/ 

bool check_equation(Point const point_a, Point const point_b, Point const check_point, Point const point, std::string straigh_name, std::string point_name)
{

    Point const vector_ab = get_vecteur(point_a, point_b);
    Point const vector_ap = get_vecteur(point_a, point);
    Point const vector_ac = get_vecteur(point_a, check_point);
    
    Fixed res_equation_point = cross_procduct(vector_ab, vector_ap);
    Fixed res_equation_check_point = cross_procduct(vector_ab, vector_ac);

    std::cout << "\nThe resultat for parametric equation for the point P is " << res_equation_point << "\n";
    std::cout << "The resultat for parametric equation for the check point " << point_name << " is " << res_equation_check_point << "\n\n";
    
    if (res_equation_point == 0)
    {
        std::cout << "The point P is on the line " << straigh_name << "\n";
        std::cout << "Because the result of the cross product is 0.\n";
        std::cout << "cross_procduct(vector_ab, vector_ap) = " << res_equation_point << "\n";
        return (false);
    }
        
    if ((res_equation_check_point > 0 && res_equation_point > 0) || (res_equation_check_point < 0 && res_equation_point < 0))
    {
        std::cout << "The point P is right side of the line " << straigh_name << "\n";
        std::cout << "Because the result of the equation has the same sign with the check point\n";
        std::cout << "sign of the equation with point P = " << get_sign(res_equation_point) << "\n";
        std::cout << "sign of the equation with point " << point_name << " = " << get_sign(res_equation_check_point) << "\n";
        return (true);
    }
    
    std::cout << "The point P is wrong side of the line " << straigh_name << "\n";
    std::cout << "Because the result of the equation has different sign with the check point\n";
    std::cout << "sign of the equation with point P = " << get_sign(res_equation_point) << "\n";
    std::cout << "sign of the equation with point " << point_name << " = " << get_sign(res_equation_check_point) << "\n";
    return (false);
}

bool methode_2(Point const point_a, Point const point_b, Point const point_c, Point const point)
{
    bool equation1 = check_equation(point_a, point_b, point_c, point, "AB", "C");
    bool equation2 = check_equation(point_a, point_c, point_b, point, "AC", "B");
    bool equation3 = check_equation(point_b, point_c, point_a, point, "BC", "A");
    
    if (equation1 && equation2 && equation3)
    {
        std::cout << "Return " << GREEN << "true" << RESET << "\n";
        return (true);
    }
    std::cout << "Return " << RED << "false" << RESET << "\n";
    return (false);
}


/*===================*/
/*=====Methode 3=====*/
/*===================*/

//(X_B - X_A)(Y_C - Y_A) - (X_C - X_A)(Y_B - Y_A)
//AB = (X_B - X_A, Y_B - Y_A)
//AC = (X_C - X_A, Y_C - Y_A)
//cross product (AB, AC)

bool methode_3(Point const point_a, Point const point_b, Point const point_c, Point const point)
{  
    //Vector of points of the triangle
    Point const vector_ab = get_vecteur(point_a, point_b);
    Point const vector_ac = get_vecteur(point_a, point_c);
    Point const vector_bc = get_vecteur(point_b, point_c);
    
    //Vector with the Point P
    Point const vector_ap = get_vecteur(point_a, point);
    Point const vector_bp = get_vecteur(point_b, point);
    
    //Calcul area main triangle
    Fixed area_main_triangle = cross_procduct(vector_ab, vector_ac);

    //Calcul triangle with the point
    Fixed area_triangle_abp = abs(cross_procduct(vector_ab, vector_ap)); 
    Fixed area_triangle_acp = abs(cross_procduct(vector_ac, vector_ap));
    Fixed area_triangle_bcp = abs(cross_procduct(vector_bc, vector_bp));

    std::cout << "The Area of the Main triange is " << area_main_triangle << "\n";

    std::cout << "The Area of the ABP triange is " << area_triangle_abp << "\n";
    std::cout << "The Area of the ACP triange is " << area_triangle_acp << "\n";
    std::cout << "The Area of the BCP triange is " << area_triangle_bcp << "\n";

    Fixed sum_area = area_triangle_abp + area_triangle_acp + area_triangle_bcp;

    if (roundf(sum_area.toFloat()) > roundf(area_main_triangle.toFloat()))
    {
        std::cout << "\nThe sum of area of the sub-triangle is greater than to the main triangle.\nThe point is not in the triangle\n";
        std::cout << "Sum area equal + area main triangle: " << sum_area << " > " << area_main_triangle << "\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    
    if (area_triangle_abp == 0)
    {
        std::cout << "\nThe area of the triangle ABP is null. That means the point P is on the straight AB\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    if (area_triangle_acp == 0)
    {
        std::cout << "\nThe area of the triangle ACP is null. That means the point P is on the straight AC\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
        if (area_triangle_bcp == 0)
    {
        std::cout << "\nThe area of the triangle BCP is null. That means the point P is on the straight BC\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";
        return (false);
    }
    
    std::cout << "\nThe sum of area of the sub-triangne is equal to the main triangle.\nThe point is in the triangle\n";
    std::cout << "Sum area equal + area main triangle: " << sum_area << " == " << area_main_triangle << "\n";
    std::cout << "Any area of the sub-triangle aren't null. That means the point P is not on the edge of the triangle\n";
    std::cout << "Return " << GREEN << "true" << RESET << "\n";
    return (true); 
}
 
bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    bool is_inside;
    
    std::cout << "\n\n=============================\n";
    std::cout << "**Point Position**\n";
    std::cout << "Point A: " << a << "\n";
    std::cout << "Point B: " << b << "\n";
    std::cout << "Point C: " << c << "\n";
    std::cout << "Point P: " << point << "\n\n";

    
    /*=====Methode 1=====*/
    std::cout << "Methode 1\n";
    methode_1(a, b, c, point);

    
    /*=====Methode 2=====*/
    std::cout << "\n\nMethode 2\n";
    methode_2(a, b, c, point);
    
    /*=====Methode 3=====*/
    std::cout << "\n\nMethode 3\n";
    is_inside = methode_3(a, b, c, point);
    
    return (is_inside);
}