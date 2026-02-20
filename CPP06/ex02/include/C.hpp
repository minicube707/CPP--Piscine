/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:48 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:36:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Base.hpp"

class C: public Base
{
    //By Default everything is public
    C();
    ~C();
    C operator= (const C& other);
};