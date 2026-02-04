/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:02:47 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 15:31:14 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

//DiamondTrap hérite de ScavTrap et de FragTrap
//Tout ce qui est public et protected dans ScavTrap et FragTrap reste accessible dans DiamondTrap
class DiamondTrap : public ScavTrap, public FragTrap
{   
    private:
        std::string _name;
        
        // ====================
        // ==   Added Init   ==
        // ====================
        DiamondTrap();
        
    public:
    
        /**************************************************
        *                INITIALISATION
        **************************************************/
        
        // ====================
        // == Canonical Form ==
        // ====================
        DiamondTrap(std::string name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap& operator=(const DiamondTrap& other);
        
        /**************************************************
        *                Methode
        **************************************************/
        
        /*
        Dans ce cas de diamond trap, ScavTrap redéfinit la méthode attack() alors que FragTrap hérite
        simplement de celle de ClapTrap. Lors de l’appel à DiamondTrap.attack(), le compilateur choisit
        la méthode la plus proche dans la hiérarchie : ScavTrap::attack(). La version héritée
        de ClapTrap via FragTrap est masquée (name hiding), ce qui évite toute ambiguïté. Ce
        comportement est résolu à la compilation car attack() n’est pas virtuelle.
        */
        // ====================
        // ==   Mandatory    ==
        // ====================
        void whoAmI();
        
        // ====================
        // == Added Methode  ==
        // ====================
        void print_stat(void);
};

#endif