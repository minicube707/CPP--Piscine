/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:45:26 by florent           #+#    #+#             */
/*   Updated: 2026/01/09 16:50:02 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _dark_secret;
        
	public:
        Contact();
        ~Contact(void);
        
        /*Get*/
        std::string get_FirstName();
        std::string get_LastName();
        std::string get_NickName();
        std::string get_PhoneNumber();
        std::string get_DarkSecret();
        
        /*Set*/
        void set_FirstName(std::string string);
        void set_LastName(std::string string);
        void set_NickName(std::string string);
        void set_PhoneNumber(std::string string);
        void set_DarkSecret(std::string string);
        
        /*Utils*/
        int empty_Contact();
        
};

#endif