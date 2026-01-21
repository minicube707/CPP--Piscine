/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:58:59 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:38:50 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*Initialisation*/
Harl::Harl()
{
    std::cout << "\n[SERVER] Player \"Harl\" 2.0 joined the server\n\n";
    
    _functptr[0] = &Harl::debug;
	_functptr[1] = &Harl::info;
	_functptr[2] = &Harl::warning;
	_functptr[3] = &Harl::error;
    _functptr[4] = &Harl::wrong_input;
}
Harl::~Harl(){std::cout << "\n[SERVER] Player \"Harl\" 2.0 left the server\n";}

/*Methode Public*/
void Harl::complain( std::string level )
{   
    /*Tab string*/
    std::string tab_string[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 4 && level != tab_string[i])
        i++;
    (this->*_functptr[i])();
}

/*Methode Private*/
void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle -special-ketchup burger. I really do!\n";
}
void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}
void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
void Harl::wrong_input( void )
{
    std::cout << "Wrong input, the correct answers are 'DEBUG', 'INFO', 'WARNING' or 'ERROR'\n";
}