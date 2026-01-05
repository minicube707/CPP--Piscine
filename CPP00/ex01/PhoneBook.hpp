/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:16:57 by florent           #+#    #+#             */
/*   Updated: 2026/01/05 23:02:57 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class	Phonebook
{
	public:
		Phonebook(void);
		~Phonebook(void);
        Contact contact[8];
        int index;
        void add();
        void search();
        std::string get_input_user(std::string ask);
        void short_string(std::string string);
};

#endif