/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/28 14:41:16 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

//Constructer
ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_energy(10)
{
    std::cout << "\nCreate a Clap Trap\n";
    print_stat();
}

//Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "\nDestroy a Clap Trap\n";
}

//Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name), _hit_point(other._hit_point), _energy_point(other._energy_point), _attack_energy(other._attack_energy)
{
    std::cout << "\nCopy a Clap Trap\n";
    print_stat();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "\nAssigned a Clap Trap\n";
    
    if (this == &other)
    {
        print_stat();
        return (*this);
    }
        
    _name = other._name;
    _hit_point = other._hit_point;
    _energy_point = other._energy_point;
    _attack_energy = other._attack_energy;

    print_stat();
    
    return (*this);
}

/**************************************************
*                Methode
**************************************************/

/*Mandatory*/
void ClapTrap::attack(const std::string& target)
{
    if (check_energy_point() || check_hit_point())
        return ;
    
    std::cout << "\nAttack\n";
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _hit_point << " points of damage!\n";
    _energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_point > amount)
        _hit_point -= amount;
    else
        _hit_point = 0;
        
    std::cout << "\nBeing Attack\n";
    std::cout << "ClapTrap " << _name << " lost " << amount << " hit points.\n" << "New points of damage: " << _hit_point <<"\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (check_energy_point() || check_hit_point())
        return ;
        
    _hit_point += amount;
    std::cout << "\nRepaired\n";
    std::cout << "ClapTrap " << _name << " regains " << amount << " hit points.\n" << "New points of damage: " << _hit_point <<"\n";
    _energy_point -= 1;
}

/*Added*/
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
    std::cout << "Attack Energy: " << _attack_energy << "\n";
}