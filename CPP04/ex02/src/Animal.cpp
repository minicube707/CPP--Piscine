/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 17:05:29 by fmotte           ###   ########.fr       */
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
Animal::Animal(): _type(""), _brain(new Brain()) {}

//Constructor
Animal::Animal(std::string type): _type(type), _brain(new Brain()) {}

//Destructor
Animal::~Animal(){delete _brain;}

//Copy constructor
Animal::Animal(const Animal &other): _type(other._type), _brain(new Brain(*other._brain)) {}

//Copy assignment
Animal& Animal::operator=(const Animal& other)
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
void Animal::makeSound(void) const{std::cout << "Animal make sound\n";}
       
// ====================
// == Geter & Seter  ==
// ====================
const std::string Animal::getType(void) const {return _type;}

// ====================
// == Added Methode  ==
// ====================
void Animal::haveAnIdea(std::string idea, unsigned int idx) const {_brain->setIdeas(idea, idx);}
std::string Animal::tellAnIdea(unsigned int idx) const {return _brain->getIdeas(idx);}
void Animal::printIdea(void) const {for (unsigned int i = 0; i < 100; i++) std::cout << "- " << tellAnIdea(i) << "\n";}