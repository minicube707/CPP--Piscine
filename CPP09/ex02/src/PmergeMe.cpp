/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/13 19:46:26 by fmotte           ###   ########.fr       */
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

void PmergeMe::merge_sort_vector(unsigned int level)
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
    
    merge_sort_vector(++level);
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
    std::cout << "Peer Size: " << peer_size << "\n";

    std::cout << "Val max\n";
    for (unsigned int i = 0; i < vec_val_max.size(); ++i)
        std::cout << vec_val_max[i] << " ";
    std::cout << "\n";
    
    std::cout << "Rest\n";
    for (unsigned int i = 0; i < vec_rest.size(); ++i)
        std::cout << vec_rest[i] << " ";
    std::cout << "\n";
    
    std::cout << "Smallest\n";
    for (unsigned int i = 2 * peer_size; i < last_index; i += 2 * peer_size)
    {
        for (unsigned int j = 0; j < peer_size; j++)
            std::cout << _vector[i+j] << " ";
        std::cout << "Max local: " << _vector[i + peer_size - 1] << "\n";
        std::cout << "place: " << binary_search(_vector[i + peer_size - 1], vec_val_max.begin(), vec_val_max.end()) - vec_val_max.begin() << "\n\n";
    }
    
    std::cout << "MAIN\n";
    for (unsigned int i = 0; i < vec_main.size(); ++i)
        std::cout << vec_main[i] << " ";
    std::cout << "\n";
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