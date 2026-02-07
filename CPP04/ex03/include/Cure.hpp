/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:09:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:24:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{   
    private:
        const std::string _type;
    
    public:
        Cure();
        Cure(std::string const & type);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif