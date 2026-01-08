/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:59:20 by florent           #+#    #+#             */
/*   Updated: 2026/01/08 16:55:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Constructeur*/
Phonebook::Phonebook(void)
{
	std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
        this->index = 0;
        
    for (int i=0; i < 8; i++)
    {
        this->contact[i].first_name = "";
        this->contact[i].last_name = "";
        this->contact[i].nickname = "";
        this->contact[i].phone_number = "";   
        this->contact[i].dark_secret = "";   
    }
}

/*Destructeur*/
Phonebook::~Phonebook(void)
{
	std::cout << "Bye bye" << std::endl;
}

void Phonebook::add()
{
    /*Get input from user*/
    std::cout << "Vous voulez ajouter un contact\n" << std::endl;
    this->contact[index].first_name = get_input_user("Fisrt Name");
    this->contact[index].last_name = get_input_user("Last Name");
    this->contact[index].nickname = get_input_user("Nickname");
    this->contact[index].phone_number = get_input_user("Phone Number");
    
    /*Check if there is only digit in phone number*/
    if (!this->contact[index].ft_isdigit())
    {
        std::cout << "Error phone number\nContact not save\n" << std::endl;
        return;
    }
    
    this->contact[index].dark_secret = get_input_user("Dark Secret");

    /*Check if there is an empty field in contact*/
    if (this->contact[index].empty_Contact())
    {
        std::cout << "Error information\nContact not save\n" << std::endl;
        return ;
    }
    this->index++;
    this->index = this->index % 8;
}

void Phonebook::search()
{
    std::cout << "Vous chercher un contact\n" << std::endl;
    
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for (int i=0; i < 8; i++)
    {
        std::cout << "|    " << i << std::ends;
        std::cout << "     |" << std::ends;

        short_string(this->contact[i].first_name);
        std::cout << "|" << std::ends;
        short_string(this->contact[i].last_name);
        std::cout << "|" << std::ends;
        short_string(this->contact[i].nickname);
        std::cout << "|" << std::endl;
            
    }
    std::cout << "" << std::endl;
}

std::string Phonebook::get_input_user(std::string ask)
{
    std::string input;
    
    std::cout << "Enter a " << ask << " : ";
    std::getline(std::cin, input);
    
    if (std::cin.good())
        std::cout << "His " << ask << " is " << input << std::endl;
    else
    {
        std::cout << "\nError input user" << std::endl;
        input = "";
    }
    std::cout << "" << std::endl;
    return (input);
}

void Phonebook::short_string(std::string string)
{
    if (string.length() > 10)
    {
        
        std::cout << std::setw(9) << string << "." << std::ends;
    }
    else
    {
        for (size_t i=0; i < 10 - string.length(); i++)
            std::cout << " " << std::ends;
        std::cout << string << std::ends;
    }
}
