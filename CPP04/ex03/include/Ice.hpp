/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:58:55 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:25:04 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{   
    private:
        const std::string _type;
    
    public:
        Ice();
        Ice(std::string const & type);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif