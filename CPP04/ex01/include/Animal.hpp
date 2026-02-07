/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 16:52:13 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
    protected:
        std::string _type;
        
    public:

        /**************************************************
        *                INITIALISATION
        **************************************************/

        // ====================
        // == Canonical Form ==
        // ====================
        
        Animal();
        Animal(std::string type);

        //If a class has at least one virtual function,
        //or if it is used polymorphically,
        //then its destructor must be virtual.
        //call ~Cat() or ~Dog() then ~Animal() thanks to virtual
        virtual ~Animal();
        
        Animal(const Animal &other);
        Animal& operator=(const Animal& other);

        /**************************************************
        *                Methode
        **************************************************/
       
        // ====================
        // ==   Mandatory    ==
        // ====================
        //call Cat::makeSound() or Dog::makeSound(), not Animal::makeSound()
        virtual void makeSound(void) const;
        
        // ====================
        // == Geter & Seter  ==
        // ====================
        const std::string getType(void) const;

        // ====================
        // == Added Methode  ==
        // ====================
        
        /*
        ================================================================================
        RECAP OF POLYMORPHISM WITH CHILD-SPECIFIC ATTRIBUTES

        - The parent class serves only as a polymorphic interface.
        It does not know about or contain the attributes specific to child classes.

        - The methods declared here are pure virtual (=0):
        they only define the method signature and must be implemented
        in each child class.

        - Each child class can have its own private attributes (e.g., another class,
        a vector of ideas, etc.) without the parent needing to know anything
        about these attributes.

        - When working with objects via a Parent* pointer or reference,
        calls to these methods will be dispatched to the child’s implementation
        (polymorphism).

        - Typical usage example:
            Parent* e = new Child();
            e->haveAnIdea("New idea", 0);   // calls Child::haveAnIdea
            delete e;

        - Advantages:
        1. The parent remains lightweight and independent of child-specific details.
        2. Each child can manage its own attributes and behaviors.
        3. Polymorphism allows using different children transparently.

        ================================================================================
        */
        virtual void haveAnIdea(std::string idea, unsigned int idx) const = 0;
        virtual std::string tellAnIdea(unsigned int idx) const = 0;
        virtual void printIdea(void) const = 0;
        
};

#endif