/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 14:32:53 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructor Default
Cat::Cat(): Animal("Cat"){}

//Destructor
Cat::~Cat(){}

//Copy constructor
Cat::Cat(const Cat &other){_type = other._type;}

//Copy assignment
Cat& Cat::operator=(const Cat& other){if (this != &other)_type = other._type;return (*this);}

/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void Cat::makeSound(void) const{std::cout << "Cat meow\n";}
   
// ====================
// == Geter & Seter  ==
// ====================
const std::string Cat::getType(void) const {return _type;}
