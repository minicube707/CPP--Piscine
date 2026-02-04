/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/04 18:44:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
Dog::Dog(): Animal("Dog"){}

//Destructor
Dog::~Dog(){}

//Copy constructor
Dog::Dog(const Dog &other){_type = other._type;}

//Copy assignment
Dog& Dog::operator=(const Dog& other){if (this != &other)_type = other._type;return (*this);}

/**************************************************
*                Methode
**************************************************/

// ====================
// == Geter & Seter  ==
// ====================
const std::string Dog::getType(void) const {return _type;}

void Dog::makeSound(void) const
{
    std::cout << "Dog bark\n";
}