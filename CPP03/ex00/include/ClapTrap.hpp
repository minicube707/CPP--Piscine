/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:52:05 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/28 14:04:36 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hit_point;
        int _energy_point;
        int _attack_energy;
        
        ClapTrap();
        
    public:
    
        /**************************************************
        *                INITIALISATION
        **************************************************/
        
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap& operator=(const ClapTrap& other);
        
        /**************************************************
        *                Methode
        **************************************************/
        
        /*Mandatory*/
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        /*Added*/
        int check_energy_point(void);
        int check_hit_point(void);
        void print_stat(void);
};

#endif