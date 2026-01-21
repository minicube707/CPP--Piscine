/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:17:35 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:34:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{  
    private:
    	std::string _name;
        
	public:
		/*Initialisation*/
		Zombie();
		~Zombie(); 

		/*Set*/
		void setName(std::string name);
		
		/*Methode*/
		void announce(void);
};

/*Fonction*/
Zombie* zombieHorde( int N, std::string name );
        
#endif