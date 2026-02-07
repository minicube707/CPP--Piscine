/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:59:28 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:34:44 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(): _name("noby") { for (int i = 0; i < 4; i++) _inventory[i] = 0; }
Character::Character(const std::string name ): _name(name) {for (int i = 0; i < 4; i++) _inventory[i] = 0;}

Character::~Character(){}
Character::Character(const Character &other): _name(other._name)
{   
    for (int i = 0; i < 4 ; i++)
        _inventory[i] = other._inventory[i];
}

std::string const & Character::getName() const{return _name;}

void Character::equip(AMateria* m)
{
    if (m != 0)
        return;
        
    for (int i = 0; i < 4 ; i++)
    {
        if ( _inventory[i] != 0)
        {
            _inventory[i] = m->clone();
            return ;
        }
    }
}

void Character::unequip(int idx){(void) idx;}

void Character::use(int idx, ICharacter& target){(void) idx; (void) target;}