/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:05:44 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 12:11:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.tpp"
#include <bits/stdc++.h>

template <typename T> 
bool easyfind(T container, int occ)
{
    if (std::find(container.begin(), container.end(), occ) != container.end())
        return true;
    return false;
}