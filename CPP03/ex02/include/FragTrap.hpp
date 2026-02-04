/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:39:12 by florent           #+#    #+#             */
/*   Updated: 2026/02/04 17:51:19 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRP_HPP
# define FRAGTRP_HPP

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

// FragTrap inherits from ClapTrap
// Everything that is public and protected in ClapTrap remains accessible in FragTrap
class FragTrap : public ClapTrap
{   
    private:
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