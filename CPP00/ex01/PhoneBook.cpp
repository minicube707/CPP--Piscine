/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:59:20 by florent           #+#    #+#             */
/*   Updated: 2026/01/09 17:01:42 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Constructeur*/
Phonebook::Phonebook(void)
{
	std::cout << \
		"Welcome to Crappy! Created an empty phonebook for up to 8 contacts" \
		<< std::endl;
        _index = 0;
        
    for (int i=0; i < 8; i++)
    {
        _contact[i].set_FirstName("");
        _contact[i].set_LastName("");
        _contact[i].set_NickName("");
        _contact[i].set_PhoneNumber("");   
        _contact[i].set_DarkSecret("");   
    }
}

/*Destructeur*/
Phonebook::~Phonebook(void)
{
	std::cout << "Bye bye" << std::endl;
}

void Phonebook::add()
{
    std::string tmp_fn;
    std::string tmp_ln;
    std::string tmp_nn;
    std::string tmp_pn;
    std::string tmp_ds;
    
    /*Get input from user*/
    std::cout << "Vous voulez ajouter un contact\n" << std::endl;
    
    tmp_fn = get_input_user("Fisrt Name");
    if (tmp_fn == "")
        return (print_error("Error information\nContact not save\n"));
        
    tmp_ln = get_input_user("Last Name");
    if (tmp_ln == "")
        return (print_error("Error information\nContact not save\n"));
        
    tmp_nn = get_input_user("Nickname");
    if (tmp_nn == "")
        return (print_error("Error information\nContact not save\n"));
        
    tmp_pn = get_input_user("Phone Number");
    if (tmp_pn == "")
        return (print_error("Error information\nContact not save\n"));
    if (!ft_isdigit(tmp_pn)) 
        return (print_error("Error phone number\nContact not save\n"));
        
    tmp_ds = get_input_user("Dark Secret");
    if (tmp_ds == "")
        return (print_error("Error information\nContact not save\n"));
        
        
    std::cout << "Information correct\nContact save\n" << std::endl;
    
    _contact[_index].set_FirstName(tmp_fn);
    _contact[_index].set_LastName(tmp_ln);
    _contact[_index].set_NickName(tmp_nn);
    _contact[_index].set_PhoneNumber(tmp_pn);
    _contact[_index].set_DarkSecret(tmp_ds);
    
    this->_index++;
    this->_index = this->_index % 8;
}

void Phonebook::search()
{
    std::string input;
    int index;
    
    std::cout << "Vous chercher un contact\n" << std::endl;

    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    int i = 0;
    while (i < 8 && !_contact[i].empty_Contact())
    {
        std::cout << "|    " << i << std::ends;
        std::cout << "     |" << std::ends;

        short_string(_contact[i].get_FirstName());
        std::cout << "|" << std::ends;
        short_string(_contact[i].get_LastName());
        std::cout << "|" << std::ends;
        short_string(_contact[i].get_NickName());
        std::cout << "|" << std::endl;
        i++;
            
    }
    /*Get input user*/
    std::cout << "\nEntrer un index:" << std::endl;
    std::getline(std::cin, input);

    /*Cast*/
    const char *cstr = input.c_str();
    index = std::atoi(cstr);
    
    /*Check input*/
    if (index == 0 && input != "0")
        std::cout << "\nError input user: wrong input" << std::endl;  
    
    /*Check index range*/
    else if (0 > index || index > 7)
        std::cout << "\nError input user: index out of range" << std::endl;
    
    /*Check contact field*/
    else if (_contact[index].empty_Contact())
        std::cout << "\nError input user: empty field" << std::endl;
        
    else
    {
        std::cout << "\nVous avez selectionne l'index: " << index << std::endl;
        std::cout << "First Name: " << _contact[index].get_FirstName() << std::endl;
        std::cout << "Last Name: " << _contact[index].get_LastName() << std::endl;
        std::cout << "Nickname: " << _contact[index].get_NickName() << std::endl;
        std::cout << "Phone Number: " << _contact[index].get_PhoneNumber() << std::endl;
        std::cout << "Dark Secret: " << _contact[index].get_DarkSecret() << std::endl;
    }
    std::cout << "" << std::endl;
}

std::string Phonebook::get_input_user(std::string ask)
{
    std::string input;
    
    std::cout << "Enter a " << ask << " : ";
    std::getline(std::cin, input);
    std::replace(input.begin(), input.end(), '\t', ' '); // replace all '\t' to ' '
    
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
        std::cout << string.substr(0, 9) << std::ends;
        std::cout << "." << std::ends;
    } 
    else
    {
        for (size_t i=0; i < 10 - string.length(); i++)
            std::cout << " " << std::ends;
        std::cout << string << std::ends;
    }
}

int ft_isdigit(std::string phone_number)
{
    for (size_t i = 0; i < phone_number.length(); i++)
    {
        if (phone_number[i] < '0' || phone_number[i] > '9')
            return (0);
    }
    return (1);
}

void print_error(std::string string)
{
    std::cout << string << std::endl;
}