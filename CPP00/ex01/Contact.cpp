/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:45:10 by florent           #+#    #+#             */
/*   Updated: 2026/01/09 16:49:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*Constructeur*/
Contact::Contact() {}

/*Destructeur*/
Contact::~Contact(void) {}

int Contact::empty_Contact()
{
    if (_first_name == "")
        return (1);
    if (_last_name == "")
        return (1);
    if (_nickname == "")
        return (1);
    if (_phone_number == "")
        return (1);
    if (_dark_secret == "")
        return (1);
    return (0);
}

/*Get*/
std::string Contact::get_FirstName() {return (_first_name);}
std::string Contact::get_LastName() {return (_last_name);}
std::string Contact::get_NickName() {return (_nickname);}
std::string Contact::get_PhoneNumber() {return (_phone_number);}
std::string Contact::get_DarkSecret() {return (_dark_secret);}

/*Set*/
void Contact::set_FirstName(std::string string) {_first_name = string;}
void Contact::set_LastName(std::string string) {_last_name = string;}
void Contact::set_NickName(std::string string) {_nickname = string;}
void Contact::set_PhoneNumber(std::string string) {_phone_number = string;}
void Contact::set_DarkSecret(std::string string) {_dark_secret = string;}