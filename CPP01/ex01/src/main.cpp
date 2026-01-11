/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:59:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/11 17:44:14 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{   
    std::cout << "Create hord of zombie\n" << std::ends; 
    Zombie *z;
    z = zombieHorde(8, "MAT");
    
    std::cout << "\nCall of all zombie\n" << std::ends; 
    for (int i=0; i < 8; i++)
        z[i].announce();

    std::cout << "\nDestroy all zombie\n" << std::ends;

    //new[] -> delete[]
    delete[]z;
    
    return (0);
}