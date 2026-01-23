/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/24 00:23:10 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

# define FIXE_POINT 0
# define CONST_EIGHT 8

class	Fixed
{  
    private: 
        int _fixed_point;
        static int const _const = CONST_EIGHT;
    
    /*CANONICAL FORM; default constructor, destructor, copy constructor and copy assignement*/
    public:
        Fixed();                                //Constructer
        ~Fixed();                               //Destructor
        Fixed(const Fixed &other);              //Copy constructor
        Fixed& operator=(const Fixed& other);   //Copy assignment operator overload

        /*Get Set*/
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
      
#endif