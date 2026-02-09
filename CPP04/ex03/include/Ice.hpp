/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:58:55 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/09 14:51:25 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{   
    public:
        Ice();
        Ice(std::string const & type);
        ~Ice();

        std::string const & getType() const;
        
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif