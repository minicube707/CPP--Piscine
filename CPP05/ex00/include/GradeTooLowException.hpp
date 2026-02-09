/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:24:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/09 19:52:20 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <string>

class GradeTooLowException : public std::exception 
{
    public:
        const char* what() const noexcept override {return "Error: grade too low";};
};