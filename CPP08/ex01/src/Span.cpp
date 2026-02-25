/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:18 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 14:50:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructor
Span::Span(unsigned int N): _size(0), _max_size(N) {check_max_len(N); _array = new int[N]();}


//Destructor
Span::~Span(){delete[] _array;}


//Copy Constructor
Span::Span(const Span& other): _array(0), _size(0), _max_size(0) {*this = other;} //Don't forget to init the _array and _size for the copy assignement


//Copy Assignement
Span& Span::operator=(const Span& other)
{
    //If other is equal to this. Do nothing
    if (this == &other) 
        return (*this);
    
    //Regenerate new array
    delete[] _array;
    _array = new int[_max_size]();
    
    //Copy the value
    unsigned int i = 0;
    while (i < other._max_size)
    {
        _array[i] = other._array[i];
        i++;
    }
    _size = i;
    return (*this);
}


//Getter
unsigned int Span::get_size(void) const {return _size;}
unsigned int Span::get_max_size(void) const {return _max_size;}

//Overload
int& Span::operator[](unsigned int index)
{
    if (index > _max_size)
        throw Span::ExecptionIndexOutOfRange();
    return _array[index];
}

const int& Span::operator[](unsigned int index) const
{
    return const_cast<Span*>(this)->operator[](index);
}
   

//Methode Mandatory
void Span::addNumber(int n)
{
    if (_size + 1 > _max_size)
        throw Span::ExeptionSpanFilled();
        
    _array[_size] = n;
    _size++;
}


//Methode Additional
void Span::check_max_len(unsigned int n)
{
    if (n > LEN_MAX)
        throw Span::ExecptionMaxSizeReached();
}

//Overlaod Os
std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    os << "Span \n";
    os << "Size: " << obj.get_size() << "\n";
    os << "Max Size: " << obj.get_max_size() << "\n";
    os << "Value: ";
    
    for (unsigned int i = 0; i < obj.get_size(); i++)
        os << obj[i] << " ";
        
    os << "\n";
    return os;
}