/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:17:54 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 18:47:50 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdint.h>    //uintptr_t
# include "Data.hpp"    //Class Data

class Serializer
{
    private:
        // Prevent instantiation of Serializer
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer operator=(const Serializer &other);
        
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

