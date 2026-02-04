/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:05 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/04 17:44:53 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

//ScavTrap hérite de ClapTrap
//Tout ce qui est public et protected dans ClapTrap reste accessible dans ScavTrap
class ScavTrap : virtual public ClapTrap
{   
    protected:

        bool _gate_keeper_mode;

        // ====================
        // ==   Added Init   ==
        // ====================
        
        static const unsigned int _init_hit_point = 100;
        static const unsigned int _init_energy_point = 50;
        static const unsigned int _init_attack_damage = 20;
        
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
        virtual void attack(const std::string& target);
        void guardGate();

        // ====================
        // == Added Methode  ==
        // ====================
        void print_stat(void);
};

#endif