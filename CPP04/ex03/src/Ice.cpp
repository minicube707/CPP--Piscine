/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:59:14 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 17:37:59 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"
# include "ICharacter.hpp"

Ice::Ice(): _type("ice") {}
Ice::Ice(std::string const & type): _type(type) {}
Ice::~Ice(){}

AMateria* Ice::clone() const{return new Ice();}
void Ice::use(ICharacter& target){std::cout << "* shoots an ice bolt at " << target.getName()  << "*\n";}