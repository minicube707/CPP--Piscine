/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:04:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/06 17:51:02 by fmotte           ###   ########.fr       */
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

        //Use the iterator of deque
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator begin() const;
        const_iterator end() const;

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();

        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

//Include after the declaration, else the compilator crash
# include "MutantStack.tpp"