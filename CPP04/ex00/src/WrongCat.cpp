/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 13:41:57 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
WrongCat::WrongCat(): WrongAnimal("WrongCat"){}

//Destructor
WrongCat::~WrongCat(){}

//Copy constructor
WrongCat::WrongCat(const WrongCat &other){_type = other._type;}

//Copy assignment
WrongCat& WrongCat::operator=(const WrongCat& other){if (this != &other)_type = other._type;return (*this);}

/**************************************************
*                Methode
**************************************************/

// ====================
// == Geter & Seter  ==
// ====================
const std::string WrongCat::getType(void) const {return _type;}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat meow\n";
}