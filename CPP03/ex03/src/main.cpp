/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/04 15:34:00 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "DiamondTrap.hpp"

int main(void)
{   
    std::string target = "Tom";
    
    DiamondTrap diamondtrap("Emeraud");
    
    diamondtrap.print_stat();
    diamondtrap.attack(target);
    
    diamondtrap.whoAmI();
}