/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:20:25 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/13 17:38:45 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{  
    private:
        std::string _name;
        const Weapon* _weapon;
    
    public:
        /*Initialisation*/
        HumanB(std::string name);
        ~HumanB();
        
        /*Function*/
        void attack();
        void setWeapon(const Weapon& weapon);
};
   
#endif