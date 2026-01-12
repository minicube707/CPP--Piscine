/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:38:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/12 15:37:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*Initialisation*/
HumanB::HumanB(std::string name):_name(name), _weapon(""){}
HumanB::~HumanB(){}

/*Function*/
void HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    _weapon = weapon;
}