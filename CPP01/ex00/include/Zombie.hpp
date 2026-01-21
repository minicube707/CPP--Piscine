/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:17:35 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:34:32 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Difference entre Methode et Function

Fonction:
- Une fonction est un bloc de code indépendant, qui n’appartient pas à une classe.

Methode
- Une méthode est une fonction membre d’une classe.
*/

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

		/*Methode*/
		void announce(void);
};

/*Fonction*/
Zombie* newZombie( std::string name );
void randomChump( std::string name );
        
#endif