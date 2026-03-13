/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/13 16:58:06 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <sstream>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<unsigned int> _vector;
        std::list<unsigned int> _list;
        
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        bool fill_vector(int argc, char **argv);
        void fill_list();

        void merge_sort_vector(unsigned int level);
        void insertion_vector(unsigned int peer_size);
        
        unsigned int get_jacobsthal(const unsigned int n);
        
        std::vector<unsigned int>::iterator binary_search(
            const unsigned int val, 
            std::vector<unsigned int>::iterator begin, 
            std::vector<unsigned int>::iterator end
        );
};


