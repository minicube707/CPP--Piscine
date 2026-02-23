/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:17:55 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 12:45:49 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <string>
	
class GradeTooHighException : public std::exception 
{
    public:
        //Redefining the what() method of std::exception
        //'throw()': ensures that this function does not throw an exception
        //(equivalent of 'noexcept' in C++11+)
        const char* what() const throw() {return "Error: Too Hight";};
};
