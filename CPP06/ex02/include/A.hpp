/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:43 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:42:00 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Base.hpp"

class A: public Base
{
    //By Default everything is public
    A();
    ~A();
    A operator= (const A& other);
};


