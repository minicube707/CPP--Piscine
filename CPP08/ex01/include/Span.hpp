/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:21 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/06 18:08:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>
# include <algorithm>

# include <cstdlib>
# include <ctime>
# include <numeric>
# include <limits>

# include <vector>

#define LEN_MAX 1000000

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
        unsigned int get_size() const;
        unsigned int get_max_size() const;
        int get_min_value() const;
        int get_max_value() const;
        int* get_addr() const;
        
        //Iterator
        typedef int* iterator;      
        iterator begin();
        iterator end();             
        iterator begin() const;
        iterator end() const;  
        
        //Overload
        int& operator[](unsigned int index);
        const int& operator[](unsigned int index) const;
        
        //Methode Mandatory
        void addNumber(int n);
        
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        
        //Methode Additional
        void check_max_len(const unsigned int &n) const;
        void check_size_for_methode() const;
        
        
        template <typename ITER> 
        void addNumber(ITER start, ITER end_vec)
        {
            Span::iterator it_span = begin();
            ITER it_vec = start;
            int i = 0;
            
            if (start == end_vec)
            {
                _min_value = std::numeric_limits<int>::min();
                _max_value = std::numeric_limits<int>::max();
                _size = i;
                return;
            }
            
            while (it_span != end() && it_vec != end_vec)
            {
                *it_span = *it_vec;
                ++it_span;
                ++it_vec;
                ++i;
            }
            _max_value = *std::max_element(begin(), end());
            _min_value = *std::min_element(begin(), end());
            _size = i;
        }

        //Exeption
        class ExceptionSpanFilled : public std::exception 
        {
            public: const char *what() const throw() {return "Cannot add more element than the capacity";}
        };
        class ExceptionIndexOutOfRange : public std::exception 
        {
            public: const char *what() const throw() {return "Index out of range";}
        };
        class ExceptionMaxSizeReached : public std::exception 
        {
            public: const char *what() const throw() {return "Try to create a Span with a range to long";}
        };
        class ExceptionEmptyArray: public std::exception 
        {
            public: const char *what() const throw() {return "Cannot call the methode because array is empty";}
        };
        class ExceptionOneElement: public std::exception 
        {
            public: const char *what() const throw() {return "Cannot call the methode because array containt only one element";}
        };
};

//Overlaod Os
std::ostream& operator<<(std::ostream& os, const Span& obj);

