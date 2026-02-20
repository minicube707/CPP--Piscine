/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:36:33 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Base.hpp"

class B: public Base
{
    //By Default everything is public
    B();
    ~B();
    B operator= (const B&  othe);
};