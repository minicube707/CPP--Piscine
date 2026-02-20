/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:34 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/20 19:45:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Base.hpp"

class Base
{
    //By Default everything is public
    virtual ~Base();

    // ====================
    // ==   Mandatory    ==
    // ====================
    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);

    // ====================
    // == Added Methode  ==
    // ====================
    Base *generate_list(int nb);
};


