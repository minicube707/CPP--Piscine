/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 15:12:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;
        
    public:

        /**************************************************
        *                INITIALISATION
        **************************************************/

        // ====================
        // == Canonical Form ==
        // ====================
        
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog& other);

        /**************************************************
        *                Methode
        **************************************************/

        // ====================
        // ==   Mandatory    ==
        // ====================
        void makeSound(void) const;
        
        // ====================
        // == Geter & Seter  ==
        // ====================
        const std::string getType(void) const;

        // ====================
        // == Added Methode  ==
        // ====================
        void haveAnIdea(std::string idea, unsigned int idx) const;
        std::string tellAnIdea(unsigned int idx) const;
        void printIdea(void) const;
};

#endif