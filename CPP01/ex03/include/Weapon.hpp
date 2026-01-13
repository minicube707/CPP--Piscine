/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:11:14 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/13 17:44:17 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPOM_HPP
# define WEAPOM_HPP

# include <iostream>
# include <string>

class	Weapon
{  
    private:
        std::string _type;
    
    public:
        /*Initialisation*/
        Weapon(std::string type);
        ~Weapon();
        
        /*Get*/
        const std::string& getType() const;

        /*Set*/
        void setType(std::string type);
};
   
#endif