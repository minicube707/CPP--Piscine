/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:16:57 by florent           #+#    #+#             */
/*   Updated: 2026/01/09 16:53:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# include <iostream>
# include <string>
# include <iomanip>
# include <algorithm>

class	Phonebook
{
    private:
        int _index;
        Contact _contact[8];
        
	public:
		Phonebook(void);
		~Phonebook(void);
        
        void add();
        void search();
        std::string get_input_user(std::string ask);
        void short_string(std::string string);
};

int ft_isdigit(std::string phone_number);
void print_error(std::string string);

#endif