/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:42:05 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 17:52:01 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

/**************************************************
*                INITIALISATION
**************************************************/

// ====================
// == Canonical Form ==
// ====================

//Constructer
FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout << CYAN;
    std::cout << "\nCreate a FragTrap\n";
    std::cout << RESET;
    
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
    
    print_stat();
}

//Destructor
FragTrap::~FragTrap()
{
    std::cout << BLUE;
    std::cout << "\nDestroy a FragTrap\n";
    std::cout << RESET;
}

//Copy constructor
FragTrap::FragTrap(const FragTrap &other):ClapTrap(other._name)
{
    std::cout << CYAN;
    std::cout << "\nCopy a FragTrap\n";
    std::cout << RESET;
    
    _hit_point = other._hit_point;
    _energy_point = other._energy_point;
    _attack_damage = other._attack_damage;
    
    print_stat();
}

//Copy assignment
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << CYAN;
    std::cout << "\nAssigned a FragTrap\n";
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
void FragTrap::highFivesGuys(void)
{
    if (check_energy_point() || check_hit_point())
        return ;
        
    std::cout << "Give a hight five dude!!\n";
}



// ====================
// == Added Methode  ==
// ====================
void FragTrap::print_stat(void)
{
    std::cout << "\nStat FragTrap\n";
    std::cout << "Name: " << _name << "\n";
    std::cout << "Hit point: " << _hit_point << "\n";
    std::cout << "Energy Point: " << _energy_point << "\n";
    std::cout << "Attack Damage: " << _attack_damage << "\n";
}