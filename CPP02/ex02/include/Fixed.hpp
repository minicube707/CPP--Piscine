/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 13:13:39 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{  
    private: 
        //Constant
        static int const _const_eight = 8;
        static int const _const_epsilon = 1;
        static int const _init_value = 0;

        //Variable
        int _fixed_point;
        
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