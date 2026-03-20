/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/16 18:46:09 by fmotte           ###   ########.fr       */
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

unsigned int PmergeMe::get_jacobsthal(const unsigned int n)
{
    unsigned int res = 1 << n;
    
    if (n & 1)
        res += 1;
    else
        res -= 1;
        
    return res / 3;
}

// ==============================
//          VECTOR
// ==============================

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

void PmergeMe::merge_insertoin_sort_vector(unsigned int level)
{
    unsigned int max_fisrt;
    unsigned int max_second;
    std::vector<int>::iterator mid_peer;
    const unsigned int peer_size = 1 << level;
    
    if (peer_size > _vector.size())
        return;
    
    //Skip the peer of size 1, because the greater and the smallest isn't distinct
    if (level > 0)
    {
        //For each peer
        for (unsigned int i = 0; i + peer_size <= _vector.size(); i += peer_size)
        {  
            std::vector<int> peer(_vector.begin() + i, _vector.begin() + i + peer_size);
            
            max_fisrt = peer[(peer_size / 2) - 1];
            max_second = peer[peer_size - 1];
            
            //If the first is greater than the second, swap
            if (max_fisrt > max_second)
            {
                mid_peer = peer.begin() + (peer_size / 2);
                std::swap_ranges(peer.begin(), mid_peer, mid_peer);
                std::copy(peer.begin(), peer.end(), _vector.begin() + i);  
            } 
        }
    }
    merge_insertoin_sort_vector(++level);
    insertion_vector(peer_size);
}

void PmergeMe::insertion_vector(const unsigned int peer_size)
{
    std::vector<unsigned int> vec_main;
    const unsigned int last_index = ((_vector.size()) / peer_size) * peer_size;

    //Add the first smallest peer
    vec_main.insert(vec_main.begin(), _vector.begin(), _vector.begin() + peer_size);
    
    //Add the greater peer
    for (unsigned int i = peer_size; i < last_index; i += 2 * peer_size)
        vec_main.insert(vec_main.end(), _vector.begin() + i, _vector.begin() + i + peer_size);
        
    //insertion find the place for the smallest
    insertion_smallest_peer_vector(vec_main, peer_size, last_index);

    //Add the rest
    vec_main.insert(vec_main.end(), _vector.begin() + last_index, _vector.end());

    //Assign the _vector, the sort vector
    _vector.assign(vec_main.begin(), vec_main.end());
}

void PmergeMe::insertion_smallest_peer_vector(
    std::vector<unsigned int> &vec_main, 
    const unsigned int peer_size,
    const unsigned int last_index
)
{   
    std::vector<unsigned int> vec_val_max;
    
    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int next_jacobsthal_number;
    unsigned int peer_max_val;
    unsigned int index_insert;
    
    std::vector<unsigned int>::iterator begin;
    std::vector<unsigned int>::iterator end;
    
    //Create a vector with the max value of each peer
    for (unsigned int i = peer_size; i <= vec_main.size(); i += peer_size)
        vec_val_max.push_back(vec_main[i-1]);
    
    //While the jacobsthal_number is smaller than greatest index of all peer
    for (unsigned int i = 2; jacobsthal_number < last_index / peer_size; ++i)
    {
        next_jacobsthal_number = get_jacobsthal(i + 1);
        
        // For every index between the next Jacobsthal number and the current Jacobsthal number, iterate backward.
        for (unsigned int j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {
            // This condition is to prevent index out of range while next_jacobsthal_numbern is greater than _vector size
            if ((j - 1) * 2 < _vector.size() / peer_size)
            {
                begin = _vector.begin() + (j - 1) * 2 * peer_size;
                peer_max_val = *(begin + peer_size - 1);
                
                index_insert = binary_search(peer_max_val, vec_val_max.begin(), vec_val_max.end()) - vec_val_max.begin();
                vec_val_max.insert(vec_val_max.begin() + index_insert, peer_max_val);
                
                end = begin + peer_size;
                vec_main.insert(vec_main.begin() + index_insert * peer_size, begin, end);
            }
        }  
        jacobsthal_number = next_jacobsthal_number;
    }
}

void PmergeMe::vector_is_sorted()
{
    for (size_t i = 1; i < _vector.size(); i++) {
        if (_vector[i - 1] > _vector[i]) 
        {
            std::cout << "The vector isn't sorted\n";
            std::cout << _vector[i - 1] << " > " << _vector[i] << "\n";
            std::cout << "Index: " << i << "\n";
            return;
        }
    }
    std::cout << "The vector is sorted\n";
    return;
}

void PmergeMe::print_vector()
{
    for (unsigned int i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << "\n";
}

// ==============================
//          LIST
// ==============================

void PmergeMe::fill_list()
{   
    std::vector<unsigned int>::iterator it = _vector.begin();
    std::vector<unsigned int>::iterator ite = _vector.end();
    
    for (; it != ite; it++)
        _list.push_back(*it);
}

void PmergeMe::merge_insertoin_sort_list(unsigned int level)
{
    unsigned int max_first;
    unsigned int max_second;
    
    std::list<unsigned int>::iterator start;
    std::list<unsigned int>::iterator end;
    std::list<unsigned int>::iterator it_first;
    std::list<unsigned int>::iterator it_second;
    std::list<unsigned int>::iterator mid_peer;
    std::list<unsigned int>::iterator dest;
    
    const unsigned int peer_size = 1 << level;
    
    if (peer_size > _list.size())
        return;
    
    //Skip the peer of size 1, because the greater and the smallest isn't distinct
    if (level > 0)
    {
        //For each peer
        for (unsigned int i = 0; i + peer_size <= _list.size(); i += peer_size)
        {  
            
            start = _list.begin();
            std::advance(start, i);

            end = start;
            std::advance(end, peer_size);

            std::list<unsigned int> peer(start, end);

            it_first = peer.begin();
            std::advance(it_first, (peer_size / 2) - 1);

            it_second = peer.begin();
            std::advance(it_second, peer_size - 1);

            max_first = *it_first;
            max_second = *it_second;

            // If the first is greater than the second, swap
            if (max_first > max_second)
            {
                mid_peer = peer.begin();
                std::advance(mid_peer, peer_size / 2);

                std::swap_ranges(peer.begin(), mid_peer, mid_peer);

                dest = _list.begin();
                std::advance(dest, i);

                std::copy(peer.begin(), peer.end(), dest);
            }
        }
    }
    merge_insertoin_sort_list(++level);
    insertion_list(peer_size);
}

void PmergeMe::insertion_list(const unsigned int peer_size)
{
    std::list<unsigned int> list_main;
    std::list<unsigned int>::iterator start;
    std::list<unsigned int>::iterator end;
    std::list<unsigned int>::iterator it_start;
    std::list<unsigned int>::iterator it_end;
    std::list<unsigned int>::iterator rest_start;
    
    unsigned int last_index = ((_list.size()) / peer_size) * peer_size;

    // Add the first smallest peer
    start = _list.begin();
    end = start;
    std::advance(end, peer_size);
    list_main.insert(list_main.begin(), start, end);

    // Add the greater peer
    for (unsigned int i = peer_size; i < last_index; i += 2 * peer_size)
    {
        it_start = _list.begin();
        std::advance(it_start, i);

        it_end = it_start;
        std::advance(it_end, peer_size);

        list_main.insert(list_main.end(), it_start, it_end);
    }

    // insertion find the place for the smallest
    insertion_smallest_peer_list(list_main, peer_size, last_index);

    // Add the rest
    rest_start = _list.begin();
    std::advance(rest_start, last_index);

    list_main.insert(list_main.end(), rest_start, _list.end());

    // Assign the sorted list
    _list.assign(list_main.begin(), list_main.end());
}

void PmergeMe::insertion_smallest_peer_list(
    std::list<unsigned int> &list_main, 
    const unsigned int peer_size,
    unsigned int last_index
)
{   
    std::list<unsigned int> vec_val_max;

    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int next_jacobsthal_number;
    unsigned int peer_max_val;
    unsigned int index_insert;

    std::list<unsigned int>::iterator it;
    std::list<unsigned int>::iterator begin;
    std::list<unsigned int>::iterator end;
    std::list<unsigned int>::iterator max_it;
    std::list<unsigned int>::iterator pos;
    std::list<unsigned int>::iterator insert_pos;
    
    // Create a list with the max value of each peer
    for (unsigned int i = peer_size; i <= list_main.size(); i += peer_size)
    {
        it = list_main.begin();
        std::advance(it, i - 1);
        vec_val_max.push_back(*it);
    }

    for (unsigned int i = 2; jacobsthal_number < last_index / peer_size; ++i)
    {
        next_jacobsthal_number = get_jacobsthal(i + 1);

        for (unsigned int j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {
            if ((j - 1) * 2 < _list.size() / peer_size)
            {
                begin = _list.begin();
                std::advance(begin, (j - 1) * 2 * peer_size);

                max_it = begin;
                std::advance(max_it, peer_size - 1);
                peer_max_val = *max_it;

                pos = binary_search(peer_max_val, vec_val_max.begin(), vec_val_max.end());
                index_insert = std::distance(vec_val_max.begin(), pos);
                vec_val_max.insert(pos, peer_max_val);

                end = begin;
                std::advance(end, peer_size);

                insert_pos = list_main.begin();
                std::advance(insert_pos, index_insert * peer_size);

                list_main.insert(insert_pos, begin, end);
            }
        }

        jacobsthal_number = next_jacobsthal_number;
    }
}

void PmergeMe::list_is_sorted()
{
    std::list<unsigned int>::iterator prev = _list.begin();
    std::list<unsigned int>::iterator curr = prev;
    ++curr;

    size_t index = 1;

    while (curr != _list.end())
    {
        if (*prev > *curr)
        {
            std::cout << "The list isn't sorted\n";
            std::cout << *prev << " > " << *curr << "\n";
            std::cout << "Index: " << index << "\n";
            return;
        }

        ++prev;
        ++curr;
        ++index;
    }

    std::cout << "The list is sorted\n";
}