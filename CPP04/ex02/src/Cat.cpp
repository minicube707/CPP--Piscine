/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:12:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 16:46:36 by fmotte           ###   ########.fr       */
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
Cat::Cat(): Animal("Cat"), _brain(new Brain()) {}

//Destructor 
Cat::~Cat(){delete _brain;}

//Copy constructor
Cat::Cat(const Cat &other): _brain(new Brain(*other._brain)) {}

//Copy assignment
Cat& Cat::operator=(const Cat& other)
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
void Cat::makeSound(void) const{std::cout << "Cat meow\n";}
   
// ====================
// == Geter & Seter  ==
// ====================
const std::string Cat::getType(void) const {return _type;}

// ====================
// == Added Methode  ==
// ====================
void Cat::haveAnIdea(std::string idea, unsigned int idx) const {_brain->setIdeas(idea, idx);}
std::string Cat::tellAnIdea(unsigned int idx) const {return _brain->getIdeas(idx);}
void Cat::printIdea(void) const {for (unsigned int i = 0; i < 100; i++) std::cout << "- " << tellAnIdea(i) << "\n";}
