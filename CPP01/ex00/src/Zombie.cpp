/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:16:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:35:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name): _name(name)
{
    std::cout << "I am a zombie" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "I am dying..., Blood, blood, blood, everywhere, HUUUU, (x_x)" << std::endl;
}

/*Methode*/
void Zombie::announce(void)
{
   std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl; 
}