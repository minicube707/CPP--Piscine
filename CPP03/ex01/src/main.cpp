/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/28 18:55:05 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main(void)
{
    std::string target = "Tom";
    
    ClapTrap claptrap("Eliot");
    ScavTrap scavtrap("Benjamin");
    
    scavtrap.guardGate();

    //illustration of attacks
    std::cout << "\nTest1--------------\n";
    for (int i = 0; i < 51; i++)
        scavtrap.attack(target);

    //illustration of repaired
    std::cout << "\nTest2--------------\n";
    ScavTrap scavtrap2 ("Guillaume");

    for (int i = 0; i < 5; i++)
    {
        scavtrap2.takeDamage(20);
        scavtrap2.attack(target);
    }

    //ilustration of copy constructor & copy assignment operator
    std::cout << "\nTest3--------------\n";
    ScavTrap scavtrapb ("Eric");
    ScavTrap scavtrap3 (scavtrapb);
    scavtrap3.beRepaired(1);
	scavtrap3.attack(target);
    
    ScavTrap scavtrap3c(scavtrap3);
	scavtrap3c.beRepaired(1);
	scavtrap3c.attack(target);

    ScavTrap scavtrap3a = scavtrap3c;
    scavtrap3a.beRepaired(1);
	scavtrap3a.attack(target);

    //illustration of death
    std::cout << "\nTest4--------------\n";
    scavtrap3a.takeDamage(500);
    scavtrap3a.attack(target);
    
    scavtrap3c.takeDamage(500);
    scavtrap3c.attack(target);
}