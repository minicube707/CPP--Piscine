/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/03 13:55:29 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main(void)
{
    std::string target = "Tom";
    
    ClapTrap claptrap("Eliot");
    FragTrap fragtrap("Benjamin");
    
    fragtrap.highFivesGuys();

    //illustration of attacks
    std::cout << "\nTest1--------------\n";
    for (int i = 0; i < 101; i++)
        fragtrap.attack(target);

    //illustration of repaired
    std::cout << "\nTest2--------------\n";
    FragTrap fragtrap2 ("Guillaume");

    for (int i = 0; i < 5; i++)
    {
        fragtrap2.takeDamage(20);
        fragtrap2.attack(target);
    }

    //ilustration of copy constructor & copy assignment operator
    std::cout << "\nTest3--------------\n";
    FragTrap fragtrapb ("Eric");
    FragTrap fragtrap3 (fragtrapb);
    fragtrap3.beRepaired(1);
	fragtrap3.attack(target);
    
    FragTrap fragtrap3c(fragtrap3);
	fragtrap3c.beRepaired(1);
	fragtrap3c.attack(target);

    FragTrap fragtrap3a = fragtrap3c;
    fragtrap3a.beRepaired(1);
	fragtrap3a.attack(target);

    //illustration of death
    std::cout << "\nTest4--------------\n";
    fragtrap3a.takeDamage(500);
    fragtrap3a.attack(target);
    
    fragtrap3c.takeDamage(500);
    fragtrap3c.attack(target);
}