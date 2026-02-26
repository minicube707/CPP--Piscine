/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:18 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/26 14:06:14 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//Constructor
Span::Span(unsigned int N):
_size(0), 
_max_size(N),
_min_value(INT_MAX),
_max_value(INT_MIN)
{
    check_max_len(N);
    _array = new int[N]();
}


//Destructor
Span::~Span(){delete[] _array;}


//Copy Constructor
Span::Span(const Span& other): _size(0), _max_size(other._max_size) {_array = new int[_max_size](); *this = other;} //Don't forget to init the _array and _size for the copy assignement


//Copy Assignement
Span& Span::operator=(const Span& other)
{
    //If other is equal to this. Do nothing
    if (this == &other) 
        return (*this);
       
    int min = INT_MAX;
    int max = INT_MIN;

    //Get the shortest size
    unsigned int len;
    if (_max_size < other._max_size)
        len = _max_size;
    else
        len = other._max_size;
        
    //Copy the value
    unsigned int i = 0;
    while (i < len)
    {
        if (other._array[i] < min)
            min = other._array[i];
        
        if (other._array[i] > max)
            max = other._array[i];
            
        _array[i] = other._array[i];
        i++;
    }
    _size = i;
    _min_value = min;
    _max_value = max;
    return (*this);
}


//Getter
unsigned int Span::get_size(void) const {return _size;}
unsigned int Span::get_max_size(void) const {return _max_size;}
int Span::get_min_value() const {return _min_value;}
int Span::get_max_value() const {return _max_value;}
int* Span::get_addr() const {return &_array[0];}

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

//Iterator
int* Span::begin() {return get_addr();}
int* Span::end() {return get_addr() + get_max_size();}
int* Span::begin() const {return get_addr();}
int* Span::end() const {return get_addr() + get_max_size();}

//Methode Mandatory
void Span::addNumber(int n)
{
    if (_size + 1 > _max_size)
        throw Span::ExeptionSpanFilled();

    //Update first min value
    if (n < _min_value)
        _min_value = n;
       
    //Update max value
    if (n > _max_value)
        _max_value = n;
        
    _array[_size] = n;
    _size++;
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end_vec)
{
    Span::iterator it_span = begin();
    std::vector<int>::iterator it_vec = start;
    int i = 0;
    
    if (start == end_vec)
    {
        _min_value = INT_MAX;
        _max_value = INT_MIN;
        _size = i;
        return;
    }
    
    while (it_span != end() && it_vec != end_vec)
    {
        *it_span = *it_vec;
        it_span++;
        it_vec++;
        i++;
    }
    _max_value = *std::max_element(begin(), end());
    _min_value = *std::min_element(begin(), end());
    _size = i;
}
  
int Span::shortestSpan()
{
    //Check if the size of the array is correct
    check_size_for_methode();
    
    Span cpy(*this);
    std::sort(cpy.begin(), cpy.end());
    
    int res = INT_MAX;
    int tmp;
    for (unsigned int i = 0; i < cpy.get_max_size() - 1; i++)
    {
        tmp = abs(cpy[i] - cpy[i + 1]);
        if (tmp < res)
            res = tmp;
    }
    return res;
}

int Span::longestSpan()
{
    //Check if the size of the array is correct
    check_size_for_methode();
    
    return abs(_max_value - _min_value);
}
        

//Methode Additional
void Span::check_max_len(unsigned int n)
{
    if (n > LEN_MAX)
        throw Span::ExecptionMaxSizeReached();
}

void Span::check_size_for_methode()
{
    if (_size == 0)
        throw Span::ExecptionEmptyArray();
        
    if (_size == 1)
        throw Span::ExecptionOneElement();
}

//Overlaod Os
std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    os << "Span \n";
    os << "Size: " << obj.get_size() << "\n";
    os << "Max Size: " << obj.get_max_size() << "\n";
    os << "Min: " << obj.get_min_value() << "\n";
    os << "Max: " << obj.get_max_value() << "\n";
    
    for (unsigned int i = 0; i < obj.get_size(); i++)
        os << obj[i] << " ";
        
    os << "\n";
    return os;
}

int abs(int n) {if (n < 0) return (-n); return (n);}