/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:38:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/12 15:39:53 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*Initialisation*/
HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon){}
HumanA::~HumanA(){}

/*Function*/
void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}