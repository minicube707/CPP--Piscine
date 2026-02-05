/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:50:18 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 16:15:57 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
Brain::Brain(){for (int i = 0; i < 100; i++) _ideas[i] = "";}

//Destructor
Brain::~Brain(){}

//Copy constructor
Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

//Copy assignment
Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return (*this);
}

/**************************************************
*                Methode
**************************************************/

// ====================
// == Geter & Seter  ==
// ====================

std::string Brain::getIdeas(unsigned int idx){if (idx > 99) return ""; return _ideas[idx];}
void Brain::setIdeas(std::string ideas, unsigned int idx){if (idx > 99) return; _ideas[idx] = ideas;}