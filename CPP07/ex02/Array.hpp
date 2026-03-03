/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:33:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/03 11:39:46 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <ctime>

// Template class definition.
// T represents the type of elements stored in the array.
template <typename T> class Array
{
    private:
        T* _array;              // Pointer to dynamically allocated array of type T
        unsigned int _size;
        
    public:
        // Constructor
        Array();
        Array(unsigned int n );
        ~Array();
        
        Array(const Array& other);
        Array& operator=(const Array& other); 

        // Subscript operator (non-const version)
        // Allows modification of elements (e.g., arr[i] = value;)
        T &operator[](unsigned int n);

        // Subscript operator (const version)
        // Allows read-only access when the Array object is const
        const T &operator[](unsigned int n) const;
        
        unsigned int size() const;
};

//Include after the declaration, else the compilator crash
#include "Array.tpp"