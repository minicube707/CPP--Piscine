/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/26 17:01:24 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define FIXE_POINT 0
# define CONST_EIGHT 8
# define EPSILON 0.003f

class	Fixed
{  
    private: 
        int _fixed_point;
        static int const _const_eight = CONST_EIGHT;
        
    public:
        //Constructer
        Fixed();                                
        Fixed(const int value);               
        Fixed(const float value);  
        
        //Destructor           
        ~Fixed();            
        
        //Copy constructor
        Fixed(const Fixed &other);   

        //Copy assignment operator overload
        Fixed& operator=(const Fixed& other);   
        
        /*Get Set*/
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        /*Methode*/
        float toFloat( void ) const;
        int toInt( void ) const;

        /*Operator Surcharge*/
        /*Comparison Operator*/
        bool operator==(const Fixed& obj) const;
        bool operator!=(const Fixed& obj) const;
        bool operator<(const Fixed& obj) const;
        bool operator<=(const Fixed& obj) const;
        bool operator>(const Fixed& obj) const;
        bool operator>=(const Fixed& obj) const;
        
        /*Arithmetic Operator*/
        Fixed operator+(const Fixed& obj) const;
        Fixed operator-(const Fixed& obj) const;
        Fixed operator-(void) const;
        Fixed operator*(const Fixed& obj) const;
        Fixed operator/(const Fixed& obj) const;

        /*Increment/Decrement Operator*/
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        /*Overloaded Member Function*/
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

/*Function*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj);
      
#endif