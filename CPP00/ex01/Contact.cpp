/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:45:10 by florent           #+#    #+#             */
/*   Updated: 2026/01/05 23:02:38 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*Constructeur*/
Contact::Contact()
{    
}

Contact::Contact(std::string first_name, std::string last_name,
     std::string nickname, std::string phone_number, std::string dark_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->dark_secret = dark_secret;
}

/*Destructeur*/
Contact::~Contact(void)
{
}

int Contact::empty_Contact()
{
    if (this->first_name == "")
        return (1);
    if (this->last_name == "")
        return (1);
    if (this->nickname == "")
        return (1);
    if (this->phone_number == "")
        return (1);
    if (this->dark_secret == "")
        return (1);
    return (0);
}

int Contact::ft_isdigit()
{
    for (size_t i = 0; i < this->phone_number.length(); i++)
    {
        if (this->phone_number[i] < '0' || this->phone_number[i] > '9')
            return (0);
    }
    return (1);
}

