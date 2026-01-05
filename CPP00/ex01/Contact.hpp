/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 20:45:26 by florent           #+#    #+#             */
/*   Updated: 2026/01/05 23:02:52 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class	Contact
{
	public:
        Contact();
		Contact(std::string first_name, std::string last_name,
            std::string nickname, std::string phone_number, std::string dark_secret);
        ~Contact(void);
        
        int empty_Contact();
        int ft_isdigit();
        
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string dark_secret;
};

#endif