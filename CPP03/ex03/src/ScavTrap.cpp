/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:19:59 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/03 15:54:19 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructer
ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << CYAN;
    std::cout << "\nCreate a ScavTrap\n";
    std::cout << RESET;
    
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
    
    _gate_keeper_mode = false;
    
    print_stat();
}

//Destructor
ScavTrap::~ScavTrap()
{
    std::cout << BLUE;
    std::cout << "\nDestroy a ScavTrap\n";
    std::cout << RESET;
}

//Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other._name)
{
    std::cout << CYAN;
    std::cout << "\nCopy a ScavTrap\n";
    std::cout << RESET;
    
    _hit_point = other._hit_point;
    _energy_point = other._energy_point;
    _attack_damage = other._attack_damage;
    
    print_stat();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << CYAN;
    std::cout << "\nAssigned a ScavTrap\n";
    std::cout << RESET;
    
    if (this == &other)
    {
        print_stat();
        return (*this);
    }
        
    _name = other._name;
    _hit_point = other._hit_point;
    _energy_point = other._energy_point;
    _attack_damage = other._attack_damage;

    print_stat();
    
    return (*this);
}

// ====================
// ==   Added Init   ==
// ====================
ScavTrap::ScavTrap(){}

/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void ScavTrap::attack(const std::string& target)
{
    if (check_energy_point() || check_hit_point())
        return ;
    
    _energy_point -= 1;   
    
    std::cout << RED;
    std::cout << "\nAttack\n";
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
    std::cout << RESET;
    
    print_stat();
}

void ScavTrap::guardGate()
{
    if (check_energy_point() || check_hit_point())
        return ;
        
    _gate_keeper_mode = true;
    std::cout << "\nScavTrap " << _name << " is now in Gate keeper mode\n";

    print_stat();
}

// ====================
// == Added Methode  ==
// ====================
void ScavTrap::print_stat(void)
{
    std::cout << "\nName: " << _name << "\n";
    std::cout << "Hit point: " << _hit_point << "\n";
    std::cout << "Energy Point: " << _energy_point << "\n";
    std::cout << "Attack Energy: " << _attack_damage << "\n";
    std::cout << "Garde keeper mode: " << _gate_keeper_mode << "\n";
}