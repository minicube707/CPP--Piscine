/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:57:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/24 00:35:28 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    /*==============*/
    /*==Main Test===*/
    /*==============*/
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    /*==============*/
    /*===My Test====*/
    /*==============*/

    /*
    std::cout << "\n\nMy test" << std::endl;

    Fixed e = 42;
    Fixed f = 42;
    Fixed g = 37;
    Fixed h = 3.1415f;
    Fixed i = 1.4142f;
    Fixed z = 0;
    Fixed o = 1;
    Fixed n = -42;
    
    std::cout << "\nComparison Operator" << std::endl;
    
    std::cout << "\nTest: ==" << std::endl;
    std::cout << e << " == " << f << ": " << (e == f) << std::endl;
    std::cout << e << " == " << g << ": " << (e == g) << std::endl;
    std::cout << e << " == " << h << ": " << (e == h) << std::endl;
    std::cout << e << " == " << i << ": " << (e == i) << std::endl;
    std::cout << i << " == " << h << ": " << (i == h) << std::endl;

    std::cout << "\nTest: !=" << std::endl;
    std::cout << e << " != " << f << ": " << (e != f) << std::endl;
    std::cout << e << " != " << g << ": " << (e != g) << std::endl;
    std::cout << e << " != " << h << ": " << (e != h) << std::endl;
    std::cout << e << " != " << i << ": " << (e != i) << std::endl;
    std::cout << i << " != " << h << ": " << (i != h) << std::endl;
    
    std::cout << "\nTest: <" << std::endl;
    std::cout << e << " < " << f << ": " << (e < f) << std::endl;
    std::cout << f << " < " << e << ": " << (f < e) << std::endl;
    std::cout << e << " < " << g << ": " << (e < g) << std::endl;
    std::cout << g << " < " << e << ": " << (g < e) << std::endl;
    std::cout << e << " < " << h << ": " << (e < h) << std::endl;
    std::cout << e << " < " << i << ": " << (e < i) << std::endl;
    std::cout << i << " < " << h << ": " << (i < h) << std::endl;
    
    std::cout << "\nTest: >" << std::endl;
    std::cout << e << " > " << f << ": " << (e > f) << std::endl;
    std::cout << f << " > " << e << ": " << (f > e) << std::endl;
    std::cout << e << " > " << g << ": " << (e > g) << std::endl;
    std::cout << g << " > " << e << ": " << (g > e) << std::endl;
    std::cout << e << " > " << h << ": " << (e > h) << std::endl;
    std::cout << e << " > " << i << ": " << (e > i) << std::endl;
    std::cout << i << " > " << h << ": " << (i > h) << std::endl;
    
    std::cout << "\nTest: <=" << std::endl;
    std::cout << e << " <= " << f << ": " << (e <= f) << std::endl;
    std::cout << f << " <= " << e << ": " << (f <= e) << std::endl;
    std::cout << e << " <= " << g << ": " << (e <= g) << std::endl;
    std::cout << g << " <= " << e << ": " << (g <= e) << std::endl;
    std::cout << e << " <= " << h << ": " << (e <= h) << std::endl;
    std::cout << e << " <= " << i << ": " << (e <= i) << std::endl;
    std::cout << i << " <= " << h << ": " << (i <= h) << std::endl;
    
    std::cout << "\nTest: >=" << std::endl;
    std::cout << e << " >= " << f << ": " << (e >= f) << std::endl;
    std::cout << f << " >= " << e << ": " << (f >= e) << std::endl;
    std::cout << e << " >= " << g << ": " << (e >= g) << std::endl;
    std::cout << g << " >= " << e << ": " << (g >= e) << std::endl;
    std::cout << e << " >= " << h << ": " << (e >= h) << std::endl;
    std::cout << e << " >= " << i << ": " << (e >= i) << std::endl;
    std::cout << i << " >= " << h << ": " << (i >= h) << std::endl;
    
    
    std::cout << "\nArithmetic Operator" << std::endl;

    std::cout << "\nTest: +" << std::endl;
    std::cout << e << " + " << f << ": " << (e + f) << std::endl;
    std::cout << e << " + " << g << ": " << (e + g) << std::endl;
    std::cout << e << " + " << h << ": " << (e + h) << std::endl;
    std::cout << e << " + " << i << ": " << (e + i) << std::endl;
    std::cout << h << " + " << i << ": " << (h + i) << std::endl;
    
    std::cout << "\nTest: -" << std::endl;
    std::cout << e << " - " << f << ": " << (e - f) << std::endl;
    std::cout << e << " - " << g << ": " << (e - g) << std::endl;
    std::cout << g << " - " << e << ": " << (g - e) << std::endl;
    std::cout << e << " - " << h << ": " << (e - h) << std::endl;
    std::cout << e << " - " << i << ": " << (e - i) << std::endl;
    std::cout << h << " - " << i << ": " << (h - i) << std::endl;
    std::cout << i << " - " << h << ": " << (i - h) << std::endl;

    std::cout << "\nTest: *" << std::endl;
    std::cout << e << " * " << f << ": " << (e * f) << std::endl;
    std::cout << e << " * " << g << ": " << (e * g) << std::endl;
    std::cout << g << " * " << e << ": " << (g * e) << std::endl;
    std::cout << e << " * " << n << ": " << (e * n) << std::endl;
    std::cout << e << " * " << h << ": " << (e * h) << std::endl;
    std::cout << e << " * " << i << ": " << (e * i) << std::endl;
    std::cout << h << " * " << i << ": " << (h * i) << std::endl;
    std::cout << i << " * " << h << ": " << (i * h) << std::endl;
    
    std::cout << "\nTest: 0 *" << std::endl;
    std::cout << z << " * " << e << ": " << (z * f) << std::endl;
    std::cout << z << " * " << f << ": " << (z * f) << std::endl;
    std::cout << z << " * " << g << ": " << (z * g) << std::endl;
    std::cout << z << " * " << h << ": " << (z * h) << std::endl;
    std::cout << z << " * " << n << ": " << (z * n) << std::endl;
    std::cout << z << " * " << i << ": " << (z * i) << std::endl;

    std::cout << "\nTest: 1 *" << std::endl;
    std::cout << o << " * " << e << ": " << (o * f) << std::endl;
    std::cout << o << " * " << f << ": " << (o * f) << std::endl;
    std::cout << o << " * " << g << ": " << (o * g) << std::endl;
    std::cout << o << " * " << h << ": " << (o * h) << std::endl;
    std::cout << o << " * " << n << ": " << (o * n) << std::endl;
    std::cout << o << " * " << i << ": " << (o * i) << std::endl;
    
    std::cout << "\nTest: /" << std::endl;
    std::cout << e << " / " << f << ": " << (e / f) << std::endl;
    std::cout << e << " / " << g << ": " << (e / g) << std::endl;
    std::cout << g << " / " << e << ": " << (g / e) << std::endl;
    std::cout << e << " / " << n << ": " << (e / n) << std::endl;
    std::cout << e << " / " << h << ": " << (e / h) << std::endl;
    std::cout << e << " / " << i << ": " << (e / i) << std::endl;
    std::cout << h << " / " << i << ": " << (h / i) << std::endl;
    std::cout << i << " / " << h << ": " << (i / h) << std::endl;
    
    std::cout << "\nTest: 0 /" << std::endl;
    std::cout << e << " / " << z << ": " << (e / z) << std::endl;
    std::cout << f << " / " << z << ": " << (f / z) << std::endl;
    std::cout << g << " / " << z << ": " << (g / z) << std::endl;
    std::cout << h << " / " << z << ": " << (h / z) << std::endl;
    std::cout << n << " / " << z << ": " << (n / z) << std::endl;
    std::cout << i << " / " << z << ": " << (i / z) << std::endl;


    std::cout << "\nIncrement/Decrement Operator" << std::endl;
    
    std::cout << "\nTest: ++" << std::endl;
    std::cout << "z:   " << z << std::endl;
    std::cout << "z++: " << z++ << std::endl;
    std::cout << "z:   " << z << std::endl;
    std::cout << "++z: " << ++z << std::endl;
    std::cout << "z:   " << z << std::endl;

    std::cout << "\nTest: --" << std::endl;
    std::cout << "z:   " << z << std::endl;
    std::cout << "z--: " << z-- << std::endl;
    std::cout << "z:   " << z << std::endl;
    std::cout << "--z: " << --z << std::endl;
    std::cout << "z:   " << z << std::endl;

    
    std::cout << "\nOverloaded Member Function" << std::endl;
    
    std::cout << "\nTest: min" << std::endl;
    std::cout << e << " min " << f << ": " << Fixed::min(e , f) << std::endl;
    std::cout << e << " min " << g << ": " << Fixed::min(e , g) << std::endl;
    std::cout << g << " min " << e << ": " << Fixed::min(g , e) << std::endl;
    std::cout << e << " min " << n << ": " << Fixed::min(e , n) << std::endl;
    std::cout << e << " min " << h << ": " << Fixed::min(e , h) << std::endl;
    std::cout << e << " min " << i << ": " << Fixed::min(e , i) << std::endl;
    std::cout << h << " min " << i << ": " << Fixed::min(h , i) << std::endl;
    std::cout << i << " min " << h << ": " << Fixed::min(i , h) << std::endl;

    std::cout << "\nTest: max" << std::endl;
    std::cout << e << " max " << f << ": " << Fixed::max(e , f) << std::endl;
    std::cout << e << " max " << g << ": " << Fixed::max(e , g) << std::endl;
    std::cout << g << " max " << e << ": " << Fixed::max(g , e) << std::endl;
    std::cout << e << " max " << n << ": " << Fixed::max(e , n) << std::endl;
    std::cout << e << " max " << h << ": " << Fixed::max(e , h) << std::endl;
    std::cout << e << " max " << i << ": " << Fixed::max(e , i) << std::endl;
    std::cout << h << " max " << i << ": " << Fixed::max(h , i) << std::endl;
    std::cout << i << " max " << h << ": " << Fixed::max(i , h) << std::endl;
    */
   
    return 0;
}
