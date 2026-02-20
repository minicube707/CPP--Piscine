/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:17:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:19:44 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
Casts in C++:

- (type)
    Classic C-style cast, simple but less explicit; can hide risky conversions.
    
- reinterpret_cast<type>
    C++ explicit cast for low-level conversions (e.g., pointer ↔ integer); use with care.
*/

uintptr_t Serializer::serialize(Data* ptr) {return reinterpret_cast<uintptr_t>(ptr);}
Data* Serializer::deserialize(uintptr_t raw) {return reinterpret_cast<Data*>(raw);}