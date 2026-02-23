/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:23 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 19:30:39 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

/*
** Function template `iter`
**
** This template takes three template parameters:
**   - ADRR : the type of the elements stored in the array
**   - LEN  : the type used to represent the array length (e.g. size_t, int)
**   - FUNC : the type of the function (or callable object) applied to each element
**
** Parameters:
**   - addr   : pointer to the first element of the array
**   - length : number of elements in the array (passed as const)
**   - func   : callable that will be invoked on every element
**
** The function iterates over the array and applies `func`
** to each element: func(addr[i]).
**
** Works with:
**   - any data type (int, char, std::string, custom class, etc.)
**   - const and non-const arrays (constness is preserved)
**   - regular functions, function templates, lambdas, functors
*/

template <typename ADRR, typename LEN, typename FUNC> 
void iter(ADRR *addr, const LEN length, FUNC func)
{
    for (LEN i = 0; i < length; ++i)
        func(addr[i]);
}