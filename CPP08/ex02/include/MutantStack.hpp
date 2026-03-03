/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:04:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/03 11:34:55 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>
# include <list>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack& other): std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other);

        typedef typename std::stack<T>::container_type::iterator iterator;
        //Use the iterator of deque
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }

        typedef
        typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }

        typedef typename std::stack<T>::container_type::const_reverse_iterator
        const_reverse_iterator;
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

//Include after the declaration, else the compilator crash
# include "MutantStack.tpp"