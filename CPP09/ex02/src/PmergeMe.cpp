/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/15 19:00:52 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _list = other._list;
    }
    return (*this);
}

bool PmergeMe::fill_vector(int argc, char **argv)
{   
    unsigned int ui;
    
    for (int i = 1 ; i < argc; i++)
    {
        std::istringstream convert(argv[i]);
        convert >> ui;
        
        if (argv[i][0] == '-')
        {
            std::cerr << "Error: Can't accept negative number (" << argv[i] << ")\n";
            return true;
        }
        
        if (convert.fail() || !convert.eof())
        {
            std::cerr << "Error: Can't convert (" << argv[i] << ") to type int\n";
            return true;
        }
        _vector.push_back(ui);
    }
    return false;
}

void PmergeMe::fill_list()
{   
    std::vector<unsigned int>::iterator it = _vector.begin();
    std::vector<unsigned int>::iterator ite = _vector.end();
    
    for (; it != ite; it++)
        _list.push_back(*it);

    it = _vector.begin();
    for (; it != ite; it++)
       std::cout << *it << " ";
    std::cout << "\n";
}

void PmergeMe::merge_insertoin_sort_vector(unsigned int level)
{
    unsigned int max_fisrt;
    unsigned int max_second;
    std::vector<int>::iterator mid_peer;
    const unsigned int peer_size = 1 << level;
    
    if (peer_size * 2 > _vector.size())
        return;

    for (unsigned int i = 0; i + peer_size <= _vector.size(); i += peer_size)
    {  
        std::vector<int> peer(_vector.begin() + i, _vector.begin() + i + peer_size);
        
        mid_peer = peer.begin() + (peer_size / 2);
        max_fisrt = *std::max_element(peer.begin(), mid_peer);
        max_second = *std::max_element(mid_peer, peer.end());
                
        if (max_fisrt > max_second)
        {
            std::swap_ranges(peer.begin(), mid_peer, mid_peer);
            std::copy(peer.begin(), peer.end(), _vector.begin() + i);  
        } 
    }
    
    std::cout << "vector:\n";
    for (unsigned int i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << "\n\n";
    
    merge_insertoin_sort_vector(++level);
    insertion_vector(peer_size);
}

void PmergeMe::insertion_vector(const unsigned int peer_size)
{
    std::vector<unsigned int> vec_main;
    std::vector<unsigned int> vec_rest;
    std::vector<unsigned int> vec_val_max;
    
    unsigned int last_index = ((_vector.size() - 1) / peer_size) * peer_size;
    vec_rest.insert(vec_rest.begin(), _vector.begin() + last_index, _vector.end());

    //Add the first smallest peer
    vec_main.insert(vec_main.begin(), _vector.begin(), _vector.begin() + peer_size);
    
    //Add the greater peer
    for (unsigned int i = peer_size; i < last_index; i += 2 * peer_size)
        vec_main.insert(vec_main.end(), _vector.begin() + i, _vector.begin() + i + peer_size);
        
    for (unsigned int i = peer_size; i <= vec_main.size(); i += peer_size)
        vec_val_max.push_back(vec_main[i-1]);
        
    //insertion find the place for the smallest
    
    //Add the rest
    //vec_main.insert(vec_main.end(), vec_rest.begin(), vec_rest.end());
    
    //delete
    // std::cout << "\n\n------------------\n";
    // std::cout << "Peer Size: " << peer_size << "\n";
    
    // std::cout << "Val max\n";
    // for (unsigned int i = 0; i < vec_val_max.size(); ++i)
    //     std::cout << vec_val_max[i] << " ";
    // std::cout << "\n";
    
    // std::cout << "Smallest\n";
    // for (unsigned int i = 2 * peer_size; i < last_index; i += 2 * peer_size)
    // {
    //     for (unsigned int j = 0; j < peer_size; j++)
    //         std::cout << _vector[i+j] << " ";
    //     std::cout << "\n";
    // }
    
    insertion_smallest_peer_vector(vec_main, vec_val_max, peer_size, last_index);
}

void PmergeMe::insertion_smallest_peer_vector(
    std::vector<unsigned int> vec_main, 
    std::vector<unsigned int> vec_val_max, 
    const unsigned int peer_size,
    unsigned int last_index
)
{   
    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int next_jacobsthal_number;
    
    std::cout << "\nMAIN\n";
    for (unsigned int i = 0; i < vec_main.size(); ++i)
        std::cout << vec_main[i] << " ";
    std::cout << "\n";
    
    for (unsigned int i = 2; jacobsthal_number < last_index / peer_size; ++i)
    {
        next_jacobsthal_number = get_jacobsthal(i + 1);
        for (unsigned int j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {
            if ((j - 1) * 2 < _vector.size() / peer_size)
            {
                unsigned int max_val = _vector[(j - 1) * 2 * peer_size + peer_size - 1];
                // std::cout << "Max " << max_val << "\n"; 
                
                unsigned int index_insert  = binary_search(max_val, vec_val_max.begin(), vec_val_max.end()) - vec_val_max.begin();
                // std::cout << "Insertoin " << index_insert << "\n"; 
                vec_val_max.insert(vec_val_max.begin() + index_insert, max_val);
                
                // for (unsigned int k = 0; k < peer_size; ++k)
                //     std::cout << _vector[(j - 1) * 2 * peer_size + k] << " ";
                // std::cout << "\n";

                std::vector<unsigned int>::iterator begin = _vector.begin() + (j - 1) * 2 * peer_size;
                std::vector<unsigned int>::iterator end = begin + peer_size;
                // std::cout << "Begin: " << begin - _vector.begin() << " End: " << end - _vector.begin() << "\n";
                // std::cout << "Insertoin index: " << index_insert * peer_size << "\n"; 
                vec_main.insert(vec_main.begin() + index_insert * peer_size, begin, end);
            }
        }  
        jacobsthal_number = next_jacobsthal_number;
    }
    //replace _vect by vec_main
    std::cout << "End MAIN\n";
    for (unsigned int i = 0; i < vec_main.size(); ++i)
        std::cout << vec_main[i] << " ";
    std::cout << "\n";
}

unsigned int PmergeMe::get_jacobsthal(const unsigned int n)
{
    unsigned int res = 1 << n;
    
    if (n & 1)
        res += 1;
    else
        res -= 1;
        
    return res / 3;
}

std::vector<unsigned int>::iterator PmergeMe::binary_search(
    const unsigned int val,
    std::vector<unsigned int>::iterator begin,
    std::vector<unsigned int>::iterator end
)
{
    if (begin == end)
        return begin;

    std::vector<unsigned int>::iterator mid = begin + (end - begin) / 2;

    if (*mid < val)
        return binary_search(val, mid + 1, end);
    else
        return binary_search(val, begin, mid);
}