/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 00:41:35 by florent           #+#    #+#             */
/*   Updated: 2026/01/24 01:26:26 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include <cmath>

#include "Fixed.hpp"

class	Point
{  
    private: 
       Fixed _x; 
       Fixed _y;
        
    public:
        //Constructer
        Point();                                           
        Point(const float x, const float y);
        
        //Destructor
        ~Point();
        
        //Copy constructor
        Point(const Point &other);
        
        //Copy assignment operator overload
        Point& operator=(const Point& other);

        /*Get Set*/
        Fixed get_x( void ) const;
        Fixed get_y( void ) const;
        void set_x( Fixed x );
        void set_y( Fixed y );
                
};
    
/*Function*/
std::ostream& operator<<(std::ostream& os, const Point& obj);

#endif