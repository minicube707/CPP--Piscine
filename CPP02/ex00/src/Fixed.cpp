/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 11:55:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructer
Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    _fixed_point = _init_value;
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
    std::cout << "getRawBits member function called\n";
    return _fixed_point;
}
void Fixed::setRawBits( int const raw )
{
    _fixed_point = raw;
}