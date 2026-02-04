/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:08:03 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 17:11:30 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructer
//Les classes de base sont toujours construites dans l’ordre où elles sont déclarées dans la classe (HEADER),
//pas dans l’ordre de la liste d’initialisation.
//(HEADER) class DiamondTrap : public ScavTrap, public FragTrap
DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    std::cout << CYAN;
    std::cout << "\nCreate a DiamondTrap\n";
    std::cout << RESET;
    
    _name = name;
     
    // Explicit initialization of statistics
    _hit_point = FragTrap::_hit_point;
    _energy_point = ScavTrap::_energy_point;
    _attack_damage = FragTrap::_attack_damage;

    print_stat();
}

//Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << BLUE;
    std::cout << "\nDestroy a DiamondTrap\n";
    std::cout << RESET;
}

//Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other): ScavTrap(other), FragTrap(other)
{
    std::cout << CYAN;
    std::cout << "\nCopy a DiamondTrap\n";
    std::cout << RESET;
    
    (void) other;
    print_stat();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << CYAN;
    std::cout << "\nAssigned a DiamondTrap\n";
    std::cout << RESET;
    
    if (this == &other)
    {
        print_stat();
        return (*this);
    }
    
    print_stat();
    
    return (*this);
}


/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void DiamondTrap::whoAmI(void)
{
    std::cout << "\nWhoamI\n";
    std::cout << "Name: " << _name << "\n";
    std::cout << "Clap Name: " << ClapTrap::_name << "\n";
}

// ====================
// == Added Methode  ==
// ====================
void DiamondTrap::print_stat(void)
{
    std::cout << "\nStat DiamondTrap\n";
    std::cout << "Name: " << _name << "\n";
    std::cout << "Clap Name: " << ClapTrap::_name << "\n";
    std::cout << "Hit point: " << _hit_point << "\n";
    std::cout << "Energy Point: " << _energy_point << "\n";
    std::cout << "Attack Damage: " << _attack_damage << "\n";
}