/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:39:12 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 15:13:33 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRP_HPP
# define FRAGTRP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

//FragTrap hérite de ClapTrap
//Tout ce qui est public et protected dans ClapTrap reste accessible dans FragTrap
// virtual permet de partager une seule instance de la classe de base commune en héritage multiple (évite le problème du diamant).
class FragTrap : virtual public ClapTrap
{   
    protected:
    
        // ====================
        // ==   Added Init   ==
        // ====================
        
        FragTrap();
        
    public:
    
        /**************************************************
        *                INITIALISATION
        **************************************************/
        
        // ====================
        // == Canonical Form ==
        // ====================
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap &other);
        FragTrap& operator=(const FragTrap& other);
        
        /**************************************************
        *                Methode
        **************************************************/
        
        // ====================
        // ==   Mandatory    ==
        // ====================
        void highFivesGuys(void);

        // ====================
        // == Added Methode  ==
        // ====================
        void print_stat(void);
};

#endif