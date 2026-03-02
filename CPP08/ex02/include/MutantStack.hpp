/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:04:10 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/02 22:53:08 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>

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
};

//Include after the declaration, else the compilator crash
# include "MutantStack.tpp"