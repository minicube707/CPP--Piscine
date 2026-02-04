/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:02:47 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 17:55:13 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// DiamondTrap inherits from ScavTrap and FragTrap
// Everything that is public and protected in ScavTrap and FragTrap remains accessible in DiamondTrap
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
        In this DiamondTrap case, ScavTrap overrides the attack() method, while FragTrap simply
        inherits it from ClapTrap. When calling DiamondTrap.attack(), the compiler chooses
        the closest method in the hierarchy: ScavTrap::attack(). The version inherited
        from ClapTrap via FragTrap is hidden (name hiding), which avoids any ambiguity.
        This behavior is resolved at compile time because attack() is not virtual.
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