/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:14:22 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/12 14:48:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):_type(type){}
Weapon::~Weapon(){}

/*Get*/
std::string& Weapon::getType(){return (_type);}

/*Set*/
void Weapon::setType(std::string type){_type = type;}