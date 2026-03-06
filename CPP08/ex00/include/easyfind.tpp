/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:05:46 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/06 17:55:31 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>  bool easyfind(T container, int occ);

template <typename T> 
bool easyfind(T container, int occ)
{
    return std::find(container.begin(), container.end(), occ) != container.end();
}