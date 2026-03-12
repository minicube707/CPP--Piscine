/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:03:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/12 19:23:09 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: too fewer arguments\n";
        return 1;
    }
    
    PmergeMe pm;
    
    if (pm.fill_vector(argc, argv))
        return 1;
        
    //pm.fill_list();
    pm.merge_sort_vector(1);
    
    return 0;
}
