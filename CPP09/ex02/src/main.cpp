/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:03:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/18 17:03:37 by fmotte           ###   ########.fr       */
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
    
    std::cout << "Before:\n";
    pm.print_vector();
    
    clock_t start_vector = clock();
    pm.init_sort_vector();
    clock_t end_vector = clock();
    
    std::cout << "\n";
    std::cout << "After:\n";
    pm.print_vector();
    
    double time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

    std::cout << "\n";
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << time_vector << "\n";

    std::cout << "\n";
    pm.vector_is_sorted();
    
    return 0;
}
