/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/28 14:50:00 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main(void)
{
    std::string target = "Tom";
    ClapTrap claptrap1 ("Benjamin");
    
    //illustration of attacks
    std::cout << "\nTest1--------------\n";
    for (int i = 0; i < 11; i++)
        claptrap1.attack(target);


    //illustration of repaired
    std::cout << "\nTest2--------------\n";
    ClapTrap claptrap2 ("Guillaume");

    for (int i = 0; i < 11; i++)
    {
        claptrap2.takeDamage(1);
        claptrap2.beRepaired(2);
    }

    
    //ilustration of copy constructor & copy assignment operator
    std::cout << "\nTest3--------------\n";
    ClapTrap claptrapb ("Eric");
    ClapTrap claptrap3 (claptrapb);
    claptrap3.beRepaired(1);
	claptrap3.attack(target);
    
    ClapTrap claptrap3c(claptrap3);
	claptrap3c.beRepaired(1);
	claptrap3c.attack(target);

    ClapTrap claptrap3a = claptrap3c;
    claptrap3a.beRepaired(1);
	claptrap3a.attack(target);

    //illustration of death
    std::cout << "\nTest4--------------\n";
    claptrap3a.takeDamage(20);
    claptrap3a.attack(target);
    
    claptrap3c.takeDamage(100);
    claptrap3c.attack(target);
}