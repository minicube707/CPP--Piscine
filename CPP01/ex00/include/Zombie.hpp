/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:17:35 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/13 17:25:50 by fmotte           ###   ########.fr       */
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
		Zombie(const std::string& name);
		~Zombie(); 

		/*Function*/
		void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
        
#endif