/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:47:29 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/05 16:44:39 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    private:
        std::string _ideas[100];
    
    public:

        /**************************************************
        *                INITIALISATION
        **************************************************/
       
        // ====================
        // == Canonical Form ==
        // ====================
        
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain& other);

        /**************************************************
        *                Methode
        **************************************************/

        // ====================
        // == Geter & Seter  ==
        // ====================
        std::string getIdeas(unsigned int idx);
        void setIdeas(std::string ideas, unsigned int idx);
};

#endif
