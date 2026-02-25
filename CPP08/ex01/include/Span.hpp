/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:21 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 14:49:30 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>

#define LEN_MAX 1000000

class Span
{
    private:
        //Default Constructor
        Span();
        
        int *_array;
        unsigned int _size;
        const unsigned int _max_size;
        
    public:
        //Constructor
        Span(unsigned int N);

        //Destructor
        ~Span();

        //Copy Constructor
        Span(const Span& other);

        //Copy Assignement
        Span& operator=(const Span& other);
        
        //Getter
        unsigned int get_size(void) const;
        unsigned int get_max_size(void) const;
        
        //Overload
        int& operator[](unsigned int index);
        const int& operator[](unsigned int index) const;
        
        //Methode Mandatory
        void addNumber(int n);
        
        //Methode Additional
        void check_max_len(unsigned int n);
        
        //Exeption
        class ExeptionSpanFilled : public std::exception 
        {
            public: const char *what() const throw() {return "Cannot add more element than the capacity";}
        };
        class ExecptionIndexOutOfRange : public std::exception 
        {
            public: const char *what() const throw() {return "Index out of range";}
        };
        class ExecptionMaxSizeReached : public std::exception 
        {
            public: const char *what() const throw() {return "Try to create a Span with a range to long";}
        };
};

//Overlaod Os
std::ostream& operator<<(std::ostream& os, const Span& obj);


