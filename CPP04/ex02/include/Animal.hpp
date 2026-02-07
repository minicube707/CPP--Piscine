/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 12:12:08 by fmotte           ###   ########.fr       */
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
        Brain* _brain;
        
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
        /*
        SUMMARY – virtual = 0 in C++

        1) virtual f() = 0
        - Declares a pure virtual method
        - Makes the class abstract
        - Forces all concrete derived classes to implement f()
        - Defines a functional contract (interface behavior)

        2) virtual ~Base() = 0
        - Makes the class abstract without enforcing behavior
        - Indicates the class is intended only as a base (blueprint)
        - Ensures safe destruction through a base-class pointer
        - The destructor MUST still have an implementation
            (e.g. Base::~Base() = default;)

        3) Constructor
        - Can never be virtual
        - Therefore can never be pure (= 0)

        Quick recap:
        - = 0 on a method     -> derived classes must implement behavior
        - = 0 on destructor   -> abstraction + safe polymorphic destruction
        */
        virtual void makeSound(void) const = 0;
        
        // ====================
        // == Geter & Seter  ==
        // ====================
        const std::string getType(void) const;

        // ====================
        // == Added Methode  ==
        // ====================
        virtual void haveAnIdea(std::string idea, unsigned int idx) const;
        virtual std::string tellAnIdea(unsigned int idx) const;
        virtual void printIdea(void) const;
        
};

#endif