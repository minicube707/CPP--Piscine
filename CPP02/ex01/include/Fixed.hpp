/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:43:58 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/13 11:59:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>


class	Fixed
{  
    private: 
        //Constant
        static int const _const_eight = 8;
        static int const _init_value = 0;

        //Variable
        int _fixed_point;
        
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