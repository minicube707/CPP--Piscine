/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:58:59 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/21 17:39:33 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*Initialisation*/
Harl::Harl(){std::cout << "\n[SERVER] Player \"Harl\" 2.0 joined the server\n\n";}
Harl::~Harl(){std::cout << "\n[SERVER] Player \"Harl\" 2.0 left the server\n";}

/*Methode Public*/
void Harl::complain( std::string level )
{   
    /*Tab string*/
    std::string tab_string[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    int i = 0;
    while (i < 5 && level != tab_string[i])
        i++;
        
    switch ( i )
    {
        case 0:
            debug();
            
        case 1:
            info();

        case 2:
            warning();

        case 3:
            error();
            break;
            
        default:
            wrong_input();
    }
}


/*Methode Private*/
void Harl::debug( void )
{
    std::cout << "\n[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle -special-ketchup burger. I really do!\n";
}
void Harl::info( void )
{
    std::cout << "\n[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
    std::cout << "\n[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}
void Harl::error( void )
{
    std::cout << "\n[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}
void Harl::wrong_input( void )
{
    std::cout << "Wrong input, the correct answers are 'DEBUG', 'INFO', 'WARNING' or 'ERROR'\n";
}
