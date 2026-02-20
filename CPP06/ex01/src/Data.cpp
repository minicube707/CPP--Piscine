/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:18:13 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 18:58:48 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _string("string"), _i(42), _f(3.14f), _d(1.4142) {}
Data::Data(std::string string, int i, float f, double d): _string(string), _i(i), _f(f), _d(d) {}

Data::~Data() {}
Data::Data(const Data &other):_string(other._string), _i(other._i), _f(other._f), _d(other._d) {}
Data Data::operator=(const Data &other)
{
    if (this == &other)
        return *this;
        
    _string = other._string;
    _i = other._i;
    _f = other._f;
    _d = other._d;
    return (*this);
}

/*--GETTER--*/
std::string Data::get_string(void) const {return _string;};
int Data::get_int(void) const {return _i;};
float Data::get_float(void) const {return _f;};
double Data::get_double(void) const {return _d;};

/*--OS-SURCHARGE--*/
std::ostream& operator<<(std::ostream& os, const Data& obj)
{
    os << "String:   " << obj.get_string() << "\n";
    os << "Interger: " << obj.get_int() << "\n";
    os << "Float:    " << obj.get_float() << "\n";
    os << "Double:   " << obj.get_double() << "\n";
    return os;
}