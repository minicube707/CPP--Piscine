/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 13:38:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
WrongAnimal::WrongAnimal(): _type(""){}

//Constructor
WrongAnimal::WrongAnimal(std::string type): _type(type){}

//Destructor
WrongAnimal::~WrongAnimal(){}

//Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other){_type = other._type;}

//Copy assignment
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){if (this != &other)_type = other._type;return (*this);}

/**************************************************
*                Methode
**************************************************/

// ====================
// == Geter & Seter  ==
// ====================
const std::string WrongAnimal::getType(void) const {return _type;}
        
void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal make sound\n";
}