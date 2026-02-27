/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:04:13 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/27 15:47:10 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class Type, class Container= stack <Type>>
class stack
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack& other){}
        MutantStack& operator=(const MutantStack& other){}
};
