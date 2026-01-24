/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/24 01:11:36 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*CANONICAL FORM*/
Fixed::Fixed(){_fixed_point = FIXE_POINT;}
Fixed::Fixed(const int value){_fixed_point = value << _const_eight;}
Fixed::Fixed(const float value){_fixed_point = roundf(value * float(1 << _const_eight));}
Fixed::~Fixed(){}
Fixed::Fixed(const Fixed &other){setRawBits(other.getRawBits());}
Fixed &Fixed::operator=(const Fixed& old){if (this == &old)_fixed_point = old.getRawBits();return (*this);}

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
Fixed Fixed::operator+(const Fixed& obj) const{return ((getRawBits() / float(1 << _const_eight)) + (obj.getRawBits() / float(1 << _const_eight)));}
Fixed Fixed::operator-(const Fixed& obj) const{return ((getRawBits() / float(1 << _const_eight)) - (obj.getRawBits() / float(1 << _const_eight)));}
Fixed Fixed::operator*(const Fixed& obj) const{return ((getRawBits() / float(1 << _const_eight)) * (obj.getRawBits() / float(1 << _const_eight)));}
Fixed Fixed::operator/(const Fixed& obj) const
{
    if (obj.getRawBits() == 0)
        return (-1);
    return ((getRawBits() / float(1 << _const_eight)) / (obj.getRawBits() / float(1 << _const_eight)));
}

/*Increment/Decrement Operator*/
Fixed& Fixed::operator++()
{
    _fixed_point += roundf(EPSILON * float(1 << _const_eight));
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    _fixed_point += roundf(EPSILON * float(1 << _const_eight));
    return (tmp);
}

Fixed& Fixed::operator--()
{
    _fixed_point -= roundf(EPSILON * float(1 << _const_eight));
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    _fixed_point -= roundf(EPSILON * float(1 << _const_eight));
    return (tmp);
}

/*Overloaded Member Function*/
Fixed& Fixed::min(Fixed& a, Fixed& b){if (a > b)return (b);return (a);}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b){if (a > b)return (b);return (a);}
Fixed& Fixed::max(Fixed& a, Fixed& b){if (a < b)return (b);return (a);}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b){if (a < b)return (b);return (a);}