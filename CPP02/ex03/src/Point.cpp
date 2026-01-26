/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:46:36 by florent           #+#    #+#             */
/*   Updated: 2026/01/26 18:19:13 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*CANONICAL FORM*/
//Constructer
Point::Point():_x(0), _y(0){}
Point::Point(const float x, const float y):_x(x), _y(y){}
Point::Point(const Fixed x, const Fixed y):_x(x), _y(y){}

//Destructor
Point::~Point(){}

//Copy constructor
Point::Point(const Point &other): _x(other.get_x()), _y(other.get_y()){}

//Copy assignment operator overload
Point &Point::operator=(const Point& old){if (this == &old)_x = old.get_x();_y = old.get_y();return (*this);}



/*Get Set*/
Fixed Point::get_x( void ) const {return (_x);}
Fixed Point::get_y( void ) const {return (_y);}
void Point::set_x( Fixed x ){_x = x;}
void Point::set_y( Fixed y ){_y = y;}

//Surcharge
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << "X: " << obj.get_x() << " Y: " << obj.get_y();
	return (os);
}

/*Arithmetic operator*/
Point Point::operator+(const Point& obj) const{return Point(_x + obj.get_x(),_y + obj.get_y());}
Point Point::operator-(const Point& obj) const{return Point(_x - obj.get_x(),_y - obj.get_y());}
Point Point::operator-(void) const{return Point(- _x, - _y);}

Point Point::operator*(const Fixed& scalire) const{return Point(_x * scalire,_y * scalire);}

/*Function*/
Fixed dot_procduct(const Point& a, const Point& b){return (Fixed(a.get_x() * b.get_x() + a.get_y() * b.get_y()));}
