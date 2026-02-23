/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:17:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 13:49:21 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {return reinterpret_cast<uintptr_t>(ptr);}
Data* Serializer::deserialize(uintptr_t raw) {return reinterpret_cast<Data*>(raw);}