/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/19 16:29:45 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructer
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _fixed_point = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    _fixed_point = value << _const_eight;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float  constructor called\n";
    _fixed_point = roundf(value * 256);
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
    this->setRawBits(other.getRawBits());
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

float Fixed::toFloat( void ) const
{
    return _fixed_point >> _const_eight;
}

int Fixed::toInt( void ) const
{
    return _fixed_point >> _const_eight;
}

//Surcharge
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}