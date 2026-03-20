/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:03:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/20 12:08:10 by fmotte           ###   ########.fr       */
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
    pm.fill_list();
    
    std::cout << "Before:\n";
    pm.print_vector();
    
    clock_t start_vector = clock();
    pm.merge_insertoin_sort_vector(0);
    clock_t end_vector = clock();
    
    clock_t start_list = clock();
    pm.merge_insertoin_sort_list(0);
    clock_t end_list = clock();
    
    std::cout << "\n";
    std::cout << "After:\n";
    pm.print_vector();
    
    double time_vector = double(end_vector - start_vector) * 1000000 / CLOCKS_PER_SEC;;
    double time_list = double(end_list - start_list) * 1000000 / CLOCKS_PER_SEC;;

    std::cout << "\n";
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << time_vector << " us\n";
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list: " << time_list << " us\n";
    
    std::cout << "\n";
    pm.vector_is_sorted();
    pm.list_is_sorted();
    
    return 0;
}
