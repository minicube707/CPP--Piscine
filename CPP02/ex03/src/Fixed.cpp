/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 17:25:12 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CANONICAL FORM*/
//Constructer
Fixed::Fixed(){_fixed_point = _init_value;}
Fixed::Fixed(const int value){_fixed_point = value << _const_eight;}
Fixed::Fixed(const float value){_fixed_point = roundf(value * float(1 << _const_eight));}

//Destructor
Fixed::~Fixed(){}

//Copy constructor
Fixed::Fixed(const Fixed &other){setRawBits(other.getRawBits());}

//Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& old){if (this != &old)_fixed_point = old.getRawBits();return (*this);}



/*Get Set*/
int Fixed::getRawBits( void ) const{return _fixed_point;}
void Fixed::setRawBits( int const raw ){ _fixed_point = raw;}

/*Methode*/
float Fixed::toFloat( void ) const{return (_fixed_point / float(1 << _const_eight));}
int Fixed::toInt( void ) const{return _fixed_point >> _const_eight;}

//Surcharge
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

/*Operator Surcharge*/
/*Comparison operator*/
bool Fixed::operator==(const Fixed& obj) const{return (getRawBits() == obj.getRawBits());}
bool Fixed::operator!=(const Fixed& obj) const{return !(*this == obj);}
bool Fixed::operator<(const Fixed& obj) const{return (getRawBits() < obj.getRawBits());}
bool Fixed::operator>(const Fixed& obj) const{return (getRawBits() > obj.getRawBits());}
bool Fixed::operator<=(const Fixed& obj) const{return !(*this > obj);}
bool Fixed::operator>=(const Fixed& obj) const{return !(*this < obj);}

/*Arithmetic operator*/
Fixed Fixed::operator+(const Fixed& obj) const{return toFloat() + (obj.toFloat());}
Fixed Fixed::operator-(const Fixed& obj) const{return toFloat() - (obj.toFloat());}
Fixed Fixed::operator-(void) const{return ( - toFloat());}
Fixed Fixed::operator*(const Fixed& obj) const{return toFloat() * (obj.toFloat());}
Fixed Fixed::operator/(const Fixed& obj) const{if (obj.getRawBits() == 0) return (-1); return toFloat() / (obj.toFloat());}

/*Increment/Decrement Operator*/
Fixed& Fixed::operator++()
{
    _fixed_point += _const_epsilon;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _fixed_point += _const_epsilon;
    return (tmp);
}

Fixed& Fixed::operator--()
{
    _fixed_point -= _const_epsilon;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _fixed_point -= _const_epsilon;
    return (tmp);
}

Fixed Fixed::operator*=(const Fixed& obj)
{
    setRawBits(getRawBits() * obj.toFloat());
    return (*this);
}

/*Overloaded Member Function*/
Fixed& Fixed::min(Fixed& a, Fixed& b){if (a > b)return (b);return (a);}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){if (a > b)return (b);return (a);}
Fixed& Fixed::max(Fixed& a, Fixed& b){if (a < b)return (b);return (a);}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){if (a < b)return (b);return (a);}

//Math
//Newton Methode
Fixed square_root(const Fixed& a)
{
    float n = a.toFloat();
    if (n < 0) return -1;   // no real square root
    if (n == 0) return 0;

    float x = n;            // initial estimate
    float eps = 1e-1f;      // precision adapted to the float

    while ((x * x - n) > eps || (n - x * x) > eps)
        x = (x + n / x) / 2.0f;
    
    Fixed res (x);
    return (res);
}

Fixed pow(const Fixed& a, int exp)
{
    Fixed res (1);
    for (int i = 0; i < exp; i++)
        res *= a;
    return (res);
}

Fixed abs(const Fixed& a) {if (a < 0) return (-a); return (a);}
int get_sign(const Fixed a){if (a < 0) return (-1); return (1);}