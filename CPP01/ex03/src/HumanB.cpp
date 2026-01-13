/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:38:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/13 17:44:36 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*Initialisation*/
HumanB::HumanB(std::string name):_name(name), _weapon(NULL){}
HumanB::~HumanB(){}

/*Function*/
void HumanB::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(const Weapon& weapon)
{
    _weapon = &weapon;
}