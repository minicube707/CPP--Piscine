/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/14 16:23:07 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed
{  
    private: 
        int _integer;
        static int const _const = 8;
        
    public:
        Fixed();        //Constructer
        ~Fixed();       //Destructor
        Fixed(const Fixed &other);              //Copy constructor
        Fixed& operator=(const Fixed& other);   //Copy assignment operator overload

        /*Get Set*/
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
      
#endif