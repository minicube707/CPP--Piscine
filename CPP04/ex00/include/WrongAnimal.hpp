/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:33:15 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 13:18:12 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
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
        
        WrongAnimal();
        WrongAnimal(std::string type);

        // If a class has at least one virtual function,
        // or if it is used polymorphically,
        // then its destructor must be virtual.
        //const Animal* j = new Dog();
        virtual ~WrongAnimal();
        
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal& operator=(const WrongAnimal& other);

        /**************************************************
        *                Methode
        **************************************************/

        // ====================
        // == Geter & Seter  ==
        // ====================
        const std::string getType(void) const;

        void makeSound(void) const;
};

#endif