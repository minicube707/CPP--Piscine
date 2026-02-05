/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 16:43:55 by fmotte           ###   ########.fr       */
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
        //const Animal* j = new Dog();
        virtual ~Animal();
        
        Animal(const Animal &other);
        Animal& operator=(const Animal& other);

        /**************************************************
        *                Methode
        **************************************************/
       
        // ====================
        // ==   Mandatory    ==
        // ====================
        virtual void makeSound(void) const;
        
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