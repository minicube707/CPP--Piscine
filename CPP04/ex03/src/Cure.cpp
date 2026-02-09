/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:09:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/09 14:54:58 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include "ICharacter.hpp"

Cure::Cure(): AMateria("cure") {}
Cure::~Cure() {}
Cure::Cure(std::string const & type) {_type = type;}

std::string const & Cure::getType() const {return _type;}

AMateria* Cure::clone() const{return new Cure();}
void Cure::use(ICharacter& target){std::cout << "* heals " << target.getName() << "’s wounds *\n";}