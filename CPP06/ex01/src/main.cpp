/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:18:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:12:19 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

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