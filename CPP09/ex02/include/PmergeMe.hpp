/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:12 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/19 16:14:14 by fmotte           ###   ########.fr       */
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
# include <utility>
	
class PmergeMe
{
    private:
        std::vector<unsigned int> _vector_main;
        std::list<unsigned int> _list_main;
        
        unsigned int _last_number;
        bool _has_last_number;
        
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
        void init_sort_vector();
        void vector_is_sorted();
        void print_vector();
        
        void insertion_smallest_peer_vector(const std::vector<std::pair<unsigned int, unsigned int> >& arr);

        void merge_vector(
            std::vector<std::pair<unsigned int, unsigned int> >& arr, 
            unsigned int left, 
            unsigned int mid, 
            unsigned int right
        );
        
        void merge_sort_vector(
            std::vector<std::pair<unsigned int, unsigned int> >& arr, 
            unsigned int left, 
            unsigned int right
        );
        
        
        
        //List
        void fill_list();
        void init_sort_list();
        void list_is_sorted();
        void print_list();
        
        void insertion_smallest_peer_list(const std::list<std::pair<unsigned int, unsigned int> >& arr);
        
        void merge_list(
            std::list<std::pair<unsigned int, unsigned int> >& arr, 
            unsigned int left, 
            unsigned int mid, 
            unsigned int right
        );

        void merge_sort_list(
            std::list<std::pair<unsigned int, unsigned int> >& arr, 
            unsigned int left, 
            unsigned int right
        );
        
};

