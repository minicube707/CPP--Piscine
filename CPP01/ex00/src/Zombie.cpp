/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:16:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/11 16:49:58 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "I am a zombie" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "I am dying..., Blood, blood, blood, everywhere, HUUUU, (x_x)" << std::endl;
}

void Zombie::announce(void)
{
   std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl; 
}