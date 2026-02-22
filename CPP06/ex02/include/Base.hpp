/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:26:34 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/22 17:15:12 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "random.hpp"

class Base
{
    //By Default everything is private
    public:
    
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
        Base **generate_list(int nb);
        void delete_list(Base **list);
        void identify_by_ptr_list(Base **list);
        void identify_by_ref_list(Base **list);
};


