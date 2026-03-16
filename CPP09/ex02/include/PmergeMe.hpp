/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/16 18:43:34 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <ctime>

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

        
        unsigned int get_jacobsthal(const unsigned int n);
        
        template <typename Iterator, typename T>
        Iterator binary_search(const T& val, Iterator begin, Iterator end)
        {
            while (begin != end)
            {
                Iterator mid = begin;
                std::advance(mid, std::distance(begin, end) / 2);

                if (*mid < val)
                    begin = ++mid;
                else
                    end = mid;
            }
            return begin;
        }
        
        //Vector
        bool fill_vector(int argc, char **argv);
        void merge_insertoin_sort_vector(unsigned int level);
        void insertion_vector(unsigned int peer_size);
        void insertion_smallest_peer_vector(
            std::vector<unsigned int> &vec_main, 
            const unsigned int peer_size,
            const unsigned int last_index
        );
        void vector_is_sorted();
        void print_vector();
        
        //List
        void fill_list();
        void merge_insertoin_sort_list(unsigned int level);
        void insertion_list(unsigned int peer_size);
        void insertion_smallest_peer_list(
            std::list<unsigned int> &vec_main, 
            const unsigned int peer_size,
            unsigned int last_index
        );
        void list_is_sorted();
};

