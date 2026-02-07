/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:50:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/07 18:34:15 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
    private:
        const std::string _name;
        const AMateria* _inventory[4];
        
    public:
        Character();
        Character(const std::string name);
        ~Character();
        Character(const Character &other);
        Character& operator=(const Character& other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif