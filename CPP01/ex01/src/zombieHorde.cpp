/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:11:08 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/11 17:45:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    //Check if N strictly positif
    if (N <= 0)
        return NULL;
    
    // Create N Zombie
    Zombie* zombiehorde = new Zombie[N];
    
    // Init N Zombie
    for (int i=0; i < N; i++)
        zombiehorde[i].setName(name);
        
    // Return first pointer
    return (zombiehorde);
}