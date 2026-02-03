/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:05 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/03 15:52:08 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

//ScavTrap hérite de ClapTrap
//Tout ce qui est public et protected dans ClapTrap reste accessible dans ScavTrap
class ScavTrap : public ClapTrap
{   
    protected:

        bool _gate_keeper_mode;

        // ====================
        // ==   Added Init   ==
        // ====================
        
        ScavTrap();
        
    public:
    
        /**************************************************
        *                INITIALISATION
        **************************************************/
        
        // ====================
        // == Canonical Form ==
        // ====================
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap& other);
        
        /**************************************************
        *                Methode
        **************************************************/
        
        // ====================
        // ==   Mandatory    ==
        // ====================
        void attack(const std::string& target);
        void guardGate();

        // ====================
        // == Added Methode  ==
        // ====================
        void print_stat(void);
};

#endif