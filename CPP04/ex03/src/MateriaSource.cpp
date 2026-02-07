/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:26:44 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:45:09 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(){ for (int i = 0; i < 4; i++) _inventory[i] = 0;}
MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria* ptr)
{
    if (ptr != 0)
        return;
        
    for (int i = 0; i < 4 ; i++)
    {
        if ( _inventory[i] == 0)
        {
            _inventory[i] = ptr->clone();
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (type == "")
        return 0;
        
    for (int i = 0; i < 4 ; i++)
    {
        if ( _inventory[i]->getType() == type)
            return _inventory[i];
    }
    return 0;
}