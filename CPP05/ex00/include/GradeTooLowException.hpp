/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:24:45 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/10 11:08:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stdexcept>
# include <string>

class GradeTooLowException : public std::exception 
{
    public:
        //Redefining the what() method of std::exception
        //'throw()': ensures that this function does not throw an exception
        //(equivalent of 'noexcept' in C++11+)
        const char* what() const throw() {return "Too Low";};
};