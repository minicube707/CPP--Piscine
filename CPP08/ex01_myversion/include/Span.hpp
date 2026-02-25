/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:21 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 18:28:28 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>
# include <algorithm> // pour std::sort

# include <cstdlib>
# include <ctime>

#define LEN_MAX 1000000

#define INT_MIN -2147483648
#define INT_MAX 2147483647

class Span
{
    private:
        //Default Constructor
        Span();
        
        int *_array;
        unsigned int _size;
        const unsigned int _max_size;
        int _min_value;
        int _max_value;
        
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
        int get_min_value() const;
        int get_max_value() const;
        int* get_addr() const;
        
        //Overload
        int& operator[](unsigned int index);
        const int& operator[](unsigned int index) const;
        
        //Methode Mandatory
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        
        //Methode Additional
        void check_max_len(unsigned int n);
        void check_size_for_methode();
        
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
        class ExecptionEmptyArray: public std::exception 
        {
            public: const char *what() const throw() {return "Cannot call the methode because array is empty";}
        };
        class ExecptionOneElement: public std::exception 
        {
            public: const char *what() const throw() {return "Cannot call the methode because array containt only one element";}
        };
};

//Overlaod Os
std::ostream& operator<<(std::ostream& os, const Span& obj);

int abs(int n);
