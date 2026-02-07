/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:27:57 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:29:05 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type){}
AMateria::AMateria(){}
AMateria::~AMateria(void){}
AMateria::AMateria(const AMateria &other): _type(other._type) {}
AMateria& AMateria::operator=(const AMateria& other) {if (this != &other) _type = other._type; return (*this);}

std::string const & AMateria::getType() const {return _type;}
void AMateria::use(ICharacter& target) {(void) target;}