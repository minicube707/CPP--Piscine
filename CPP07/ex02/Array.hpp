/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:33:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/24 16:19:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <ctime>

#include "Array.tpp"

//Constructeur
template <typename T> Array<T>::Array(): _array(0), _size(0) {}
template <typename T> Array<T>::Array(unsigned int n ): _size(n) {_array = new T[n]();}

//Copy Constructeur
template <typename T> Array<T>::Array(const Array& other): _array(0), _size(0) {*this = other;} //Don't forget to init the _array and _size for the copy assignement

//Copy Assignement
template <typename T> Array<T> &Array<T>::operator=(const Array& other) 
{
    //If other is equal to this. Do nothing
    if (this == &other) 
        return (*this); 
    
    //Delete the old array and get the size of other
    delete[] _array;
    _size = other._size;

    //If _size is 
    if (_size == 0)
    {
        _array = 0;
        return (*this);
    }
    
    _array = new T[_size]();
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
        
    return (*this);
}

//Desteucteur
template <typename T> Array<T>::~Array() {delete[] _array;}

//Overload operator
template <typename T> T &Array<T>::operator[](unsigned int n)
{
    //Check if n is greater or equal to _size
    if (n >= _size)
        throw std::out_of_range("Invalid Index");
    return _array[n];
}

template <typename T> const T &Array<T>::operator[](unsigned int n) const
{
    //Check if n is greater or equal to _size
    if (n >= _size)
        throw std::out_of_range("Invalid Index");
    return _array[n];
}

//Methode size
template <typename T> unsigned int Array<T>::size() const {return _size;};