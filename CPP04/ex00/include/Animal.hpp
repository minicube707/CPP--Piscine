/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 12:11:31 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

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

        // If a class has at least one virtual function,
        // or if it is used polymorphically,
        // then its destructor must be virtual.
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

};

#endif