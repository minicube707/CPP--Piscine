/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:18:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 13:49:28 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// reinterpret_cast: Low-level cast that reinterprets the underlying bits.
// Used for unrelated pointer conversions or memory manipulation.
// No type safety or runtime checks.
// Very dangerous — may lead to undefined behavior if used incorrectly.

int main()
{
    Data data("I am a string", 1, 1.2f, 1.23);
    std::cout << data;
    
    uintptr_t tmp;
    tmp = Serializer::serialize(&data);
    std::cout << "\nSerializer Data " << tmp << "\n";

    Data *new_data;
    new_data = Serializer::deserialize(tmp);
    std::cout << "\n";
    std::cout << *new_data;
}