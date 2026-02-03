/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:08:03 by florent           #+#    #+#             */
/*   Updated: 2026/02/03 16:01:01 by florent          ###   ########.fr       */
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
DiamondTrap::DiamondTrap(std::string name):ScavTrap(name)
{
    std::cout << CYAN;
    std::cout << "\nCreate a DiamondTrap\n";
    std::cout << RESET;
    
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
void DiamondTrap::print_stat(void)
{
    std::cout << "Print stat Diamond Trap";
}