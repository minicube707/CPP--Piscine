/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:02:47 by florent           #+#    #+#             */
/*   Updated: 2026/02/03 14:31:43 by florent          ###   ########.fr       */
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
        
        // ====================
        // == Added Methode  ==
        // ====================
        void print_stat(void);
};

#endif