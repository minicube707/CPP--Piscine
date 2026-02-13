/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 17:26:53 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructer
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _fixed_point = _init_value;
}

//Constructeur: Convert an Int to a Fix-Point
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    _fixed_point = value << _const_eight;
}

//Constructeur: Convert an Float to a Fix-Point
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    _fixed_point = roundf(value * float(1 << _const_eight));
}

//Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{   
    std::cout << "Copy constructor called\n";
    *this = other;
}

//Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed& old)
{
    std::cout << "Copy assignment operator called\n";
    
    if (this == &old)
        return (*this);

    this->_fixed_point = old.getRawBits();
    return (*this);
}

/*Get Set*/
int Fixed::getRawBits( void ) const
{
    return _fixed_point;
}
void Fixed::setRawBits( int const raw )
{
    _fixed_point = raw;
}

//Methode to convert Fix-Point to Float
float Fixed::toFloat( void ) const
{
    return (_fixed_point / float(1 << _const_eight));
}

//Methode to convert Fix-Point to Int
int Fixed::toInt( void ) const
{
    return _fixed_point >> _const_eight;
}

/*Function*/
/*
=========DESCRIPTION=========
Extra operator for displaying a Fixed object
on an output stream (e.g., std::cout).

=========INPUT=========
std::ostream& os: output stream
const Fixed& obj: Fixed object to display (passed by constant reference)

==========OUTPUT=========
std::ostream&: reference to the output stream, allowing
chaining outputs (e.g., std::cout << a << b << std::endl)

=========DETAILS=========
The Fixed object is displayed as a float using the toFloat() method.

*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}