/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:20:25 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/12 15:39:40 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{  
    private:
        std::string _name;
        Weapon &_weapon;
    
    public:
        /*Initialisation*/
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        
        /*Function*/
        void attack();
};
   
#endif