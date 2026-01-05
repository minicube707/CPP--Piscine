/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:20:02 by florent           #+#    #+#             */
/*   Updated: 2026/01/05 23:18:05 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    std::string intput;
    Phonebook phonebook;
    
    while (1)
    {
        std::cout << "Enter a command: ";
		std::getline(std::cin, intput);
        
        if (std::cin.good())
        {
            std::cout << "Your commande is: " << intput << std::endl;
            if (intput == "ADD")
                phonebook.add();
            else if (intput == "SEARCH")
                phonebook.search();
            else if (intput == "EXIT")
                break;
            else
                std::cout << "Incorect input. Please enter: ADD, SEARCH or EXIT\n" << std::endl;
        }
        else
        {
            std::cout << "\nError input user" << std::endl;
            break;
        }
    }
    return (0);
}