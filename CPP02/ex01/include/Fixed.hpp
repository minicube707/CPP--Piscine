/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/24 00:19:23 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

# define FIXE_POINT 0
# define CONST_EIGHT 8

class	Fixed
{  
    private: 
        int _fixed_point;
        static int const _const_eight = CONST_EIGHT;
        
    public:
        //Constructer
        Fixed();                                
        Fixed(const int value);               
        Fixed(const float value);  
        
        //Destructor           
        ~Fixed();            
        
        //Copy constructor
        Fixed(const Fixed &other);   

        //Copy assignment operator overload
        Fixed& operator=(const Fixed& other);   
        
        /*Get Set*/
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        /*Methode*/
        float toFloat( void ) const;
        int toInt( void ) const;
};

/*Function*/
std::ostream& operator<<(std::ostream& os, const Fixed& obj);
      
#endif