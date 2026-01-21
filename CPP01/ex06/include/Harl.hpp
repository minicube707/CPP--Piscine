/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:59:03 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:39:19 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class	Harl
{  
    private: 

        /*Methode*/
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        void wrong_input( void );
        
    public:
        /*Initialisation*/
        Harl();
        ~Harl();

        /*Methode*/
        void complain(std::string level);
};
      
#endif