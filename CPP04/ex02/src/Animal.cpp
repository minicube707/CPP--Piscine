/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 16:54:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
Animal::Animal(): _type("") {}

//Constructor
Animal::Animal(std::string type): _type(type) {}

//Destructor
Animal::~Animal(){}

//Copy constructor
Animal::Animal(const Animal &other): _type(other._type) {}

//Copy assignment
Animal& Animal::operator=(const Animal& other)
{
    if (this == &other) 
        return *this;
    _type = other._type;
    return *this;
}

/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void Animal::makeSound(void) const{std::cout << "Animal make sound\n";}
       
// ====================
// == Geter & Seter  ==
// ====================
const std::string Animal::getType(void) const {return _type;}
