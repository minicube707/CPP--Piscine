/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/28 18:50:25 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructer
ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(10)
{
    std::cout << CYAN;
    std::cout << "\nCreate a ClapTrap\n";
    std::cout << RESET;
    
    print_stat();
}

//Destructor
ClapTrap::~ClapTrap()
{
    std::cout << BLUE;
    std::cout << "\nDestroy a ClapTrap\n";
    std::cout << RESET;
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hit_point(other._hit_point), _energy_point(other._energy_point), _attack_damage(other._attack_damage)
{
    std::cout << CYAN;
    std::cout << "\nCopy a ClapTrap\n";
    std::cout << RESET;
    
    print_stat();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << CYAN;
    std::cout << "\nAssigned a ClapTrap\n";
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

/**************************************************
*                Methode
**************************************************/

// ====================
// ==   Mandatory    ==
// ====================
void ClapTrap::attack(const std::string& target)
{
    if (check_energy_point() || check_hit_point())
        return ;
        
    _energy_point -= 1;

    std::cout << RED;
    std::cout << "\nAttack\n";
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!\n";
    std::cout << RESET;
    
    print_stat();
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_point > amount)
        _hit_point -= amount;
    else
        _hit_point = 0;
    
    std::cout << YELLOW;
    std::cout << "\nBeing Attack\n";
    std::cout << "ClapTrap " << _name << " lost " << amount << " hit points.\n" << "New hit point: " << _hit_point <<"\n";
    std::cout << RESET;
    
    print_stat();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (check_energy_point() || check_hit_point())
        return ;
        
    _hit_point += amount;
    _energy_point -= 1;
    
    std::cout << GREEN;
    std::cout << "\nRepaired\n";
    std::cout << "ClapTrap " << _name << " regains " << amount << " hit points.\n" << "New hit point: " << _hit_point <<"\n";
    std::cout << RESET;
    
    print_stat();
}

// ====================
// == Added Methode  ==
// ====================
int ClapTrap::check_energy_point(void)
{
    if (_energy_point == 0)
    {
        std::cout << "\nHaven't enough energy point.\nI am tired\n";
        return (1);
    }
    return (0);
}

int ClapTrap::check_hit_point(void)
{
    if  (_hit_point == 0)
    {
        std::cout << "\nHaven't enough hit point.\nDamm it. I am going away\n";
        return (1);
    }
    return (0);
}

void ClapTrap::print_stat(void)
{
    std::cout << "\nName: " << _name << "\n";
    std::cout << "Hit point: " << _hit_point << "\n";
    std::cout << "Energy Point: " << _energy_point << "\n";
    std::cout << "Attack Energy: " << _attack_damage << "\n";
}
