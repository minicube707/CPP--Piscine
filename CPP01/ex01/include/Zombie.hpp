/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:17:35 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/12 14:13:24 by fmotte           ###   ########.fr       */
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
		
		/*Function*/
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
        
#endif