/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:41:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 14:12:22 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

# include <string>
# include <iostream>

// Function template definition.
// "template <typename T>" declares a generic type parameter T.
// The compiler will generate a specific version of this function
// for each type used (e.g., int, double, std::string).

template <typename T> 
void swap(T &x, T &y)
{
    // T is replaced by the actual type at compile time.
    // For example, if called with int, this becomes:
    // void swap(int &x, int &y)
    
    T tmp;      // Create a temporary variable of type T
    tmp = x;
    x = y;
    y = tmp;
}

// Function template that returns a value of type T.
// The type T must support operator< for this to compile.
template <typename T> T min(T x, T y){return (x < y) ? x : y;}
template <typename T> T max(T x, T y){return (x > y) ? x : y;}