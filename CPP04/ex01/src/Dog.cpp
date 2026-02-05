/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 16:47:02 by fmotte           ###   ########.fr       */
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
Dog::Dog(): Animal("Dog"), _brain(new Brain()) {}

//Destructor
Dog::~Dog(){delete _brain;}

//Copy constructor
Dog::Dog(const Dog &other): _brain(new Brain(*other._brain)) {}

//Copy assignment
Dog& Dog::operator=(const Dog& other)
{
    if (this == &other) 
        return *this;
        
    delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void Dog::makeSound(void) const{std::cout << "Dog bark\n";}

// ====================
// == Geter & Seter  ==
// ====================
const std::string Dog::getType(void) const {return _type;}

// ====================
// == Added Methode  ==
// ====================
void Dog::haveAnIdea(std::string idea, unsigned int idx) const {_brain->setIdeas(idea, idx);}
std::string Dog::tellAnIdea(unsigned int idx) const {return _brain->getIdeas(idx);}
void Dog::printIdea(void) const {for (unsigned int i = 0; i < 100; i++) std::cout << "- " << tellAnIdea(i) << "\n";}