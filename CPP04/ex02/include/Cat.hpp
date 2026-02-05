/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:16:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 15:12:26 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
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
        
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat& other);

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