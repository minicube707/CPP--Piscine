/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:17:55 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/09 19:52:14 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <string>
	
class GradeTooHighException : public std::exception 
{
    public:
        const char* what() const noexcept override {return "Error: grade too high";};
};
