/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:39:41 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/27 18:56:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

# include <string>

/*===================*/
/*=====Methode 1=====*/
/*===================*/
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


/*===================*/
/*=====Methode 2=====*/
/*===================*/ 
Fixed equation_line(Point x, Fixed slope, Fixed biais) {return x.get_y() - slope * x.get_x() - biais;}

int check_equation(Point const point_line1, Point const point_line2, Point const check_point, Point const point)
{
    Fixed slope =  (point_line1.get_y() - point_line2.get_y()) / (point_line1.get_x() - point_line2.get_x());
    Fixed biais = point_line1.get_y() - slope * point_line1.get_x();

    if (equation_line(point, slope, biais) == 0)
        return (0);
    if (equation_line(check_point, slope, biais) > 0 && equation_line(point, slope, biais) > 0)
        return (1);
    if (equation_line(check_point, slope, biais) < 0 && equation_line(point, slope, biais) < 0)
        return (1);
    return (-1);
}

bool print_message(int equation, std::string name)
{
    if (equation == -1)
    {
        std::cout << "The point is not on the correct side of line " << name << "\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";;
        return (false); 
    }
    if (equation == 0)
    {
        std::cout << "The point is on the line " << name << "\n";
        std::cout << "Return " << RED << "false" << RESET << "\n";;
        return (false); 
    } 
    return (true);
}

bool methode_2(Point const a, Point const b, Point const c, Point const point)
{
    int equation1 = check_equation(a, b, c, point);
    int equation2 = check_equation(a, c, b, point);
    int equation3 = check_equation(b, c, a, point);
    
    if (!print_message(equation1, "AB"))
        return (false);
    if (!print_message(equation2, "AC"))
        return (false);
    if (!print_message(equation3, "BC"))
        return (false);
    
    std::cout << "The point is on the correct side for each line\n";
    std::cout << "Return " << GREEN << "true" << RESET << "\n";
    return (true);
}


/*===================*/
/*=====Methode 3=====*/
/*===================*/

//(x_2 - x_1)(y_3 - y_1) - (x_3 - x_1)(y_2 - y_1)
Fixed formula_double_area(Point const a, Point const b, Point const c) {return (b.get_x() - a.get_x()) * (c.get_y() - a.get_y()) - (c.get_x() - a.get_x()) * (b.get_y() - a.get_y());}

bool methode_3(Point const a, Point const b, Point const c, Point const point)
{  
    //Calcul area main triangle
    Fixed area_main_triangle = formula_double_area(a, b, c);

    //Calcul triangle with the point
    Fixed area_triangle_abp = abs(formula_double_area(a, b, point));
    Fixed area_triangle_acp = abs(formula_double_area(a, c, point));
    Fixed area_triangle_bcp = abs(formula_double_area(b, c, point));

    std::cout << "The Area of the Main triange is " << area_main_triangle << "\n";

    std::cout << "The Area of the ABP triange is " << area_triangle_abp << "\n";
    std::cout << "The Area of the ACP triange is " << area_triangle_acp << "\n";
    std::cout << "The Area of the BCP triange is " << area_triangle_bcp << "\n";

    Fixed sum_area = area_triangle_abp + area_triangle_acp + area_triangle_bcp;

    if (roundf(sum_area.toFloat()) > roundf(area_main_triangle.toFloat()))
    {
        std::cout << "\nThe sum of area of the sub-triangne is greater than to the main triangle.\nThe point is not in the triangle\n";
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
    
    /*=====Methode 1=====*/
    std::cout << "Methode 1\n";
    is_inside = methode_1(a, b, c, point);

    
    /*=====Methode 2=====*/
    std::cout << "\n\nMethode 2\n";
    methode_2(a, b, c, point);
    
    /*=====Methode 3=====*/
    std::cout << "\n\nMethode 3\n";
    methode_3(a, b, c, point);
    
    return (is_inside);
}