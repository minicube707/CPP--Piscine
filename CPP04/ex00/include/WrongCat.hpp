/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:16:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 13:32:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:

        /**************************************************
        *                INITIALISATION
        **************************************************/

        // ====================
        // == Canonical Form ==
        // ====================
        
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat& operator=(const WrongCat& other);

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