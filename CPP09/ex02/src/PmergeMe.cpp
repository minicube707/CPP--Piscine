/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/12 19:23:41 by fmotte           ###   ########.fr       */
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
    unsigned int peer_size = 1 << level;
    
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