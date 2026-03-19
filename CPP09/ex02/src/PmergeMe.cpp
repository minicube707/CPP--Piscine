/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/19 16:25:26 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():_last_number(0), _has_last_number(false){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector_main = other._vector_main;
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
        _vector_main.push_back(ui);
    } 
    
    if (_vector_main.size() % 2 == 1)
    {
        _has_last_number = true;
        _last_number = _vector_main.back();
    }
    return false;
}

void PmergeMe::init_sort_vector()
{
    std::vector<std::pair<unsigned int, unsigned int> > vec_peer;
    std::pair<unsigned int, unsigned int> peer;
    
    if (_vector_main.size() == 1)
        return;
        
    for (size_t i = 0; i < _vector_main.size() - 1; i += 2)
    {
        if (_vector_main[i] < _vector_main[i + 1])
            peer = std::make_pair(_vector_main[i], _vector_main[i + 1]);
        else
            peer = std::make_pair(_vector_main[i + 1], _vector_main[i]);
            
        vec_peer.push_back(peer);
    } 

    merge_sort_vector(vec_peer, 0, vec_peer.size() -1);

    insertion_smallest_peer_vector(vec_peer);
}

void PmergeMe::merge_vector(
    std::vector<std::pair<unsigned int, unsigned int> >& arr, 
    unsigned int left, 
    unsigned int mid, 
    unsigned int right
)
{         
    unsigned int n1 = mid - left + 1;
    unsigned int n2 = right - mid;
    
    // Create temp vectors
    std::vector<std::pair<unsigned int, unsigned int> > L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (unsigned int i = 0; i < n1; i++)
        L[i] = arr[left + i];
        
    for (unsigned int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    unsigned int i = 0, j = 0;
    unsigned int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) 
    {
        if (L[i].second <= R[j].second)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::merge_sort_vector(
    std::vector<std::pair<unsigned int, unsigned int> >& arr, 
    unsigned int left, 
    unsigned int right
)
{
    if (left >= right)
        return;
        
    unsigned int mid = left + (right - left) / 2;
    merge_sort_vector(arr, left, mid);
    merge_sort_vector(arr, mid + 1, right);
    merge_vector(arr, left, mid, right);
}

void PmergeMe::insertion_smallest_peer_vector(const std::vector<std::pair<unsigned int, unsigned int> >& vec_peer)
{   
    
    unsigned int next_jacobsthal_number;
    unsigned int number_to_insert;
    unsigned int add_idx;
    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int jacobsthal_offset = 0;
    
    size_t idx_upper_bound_main;
    size_t len_vec_peer = vec_peer.size();
    
    std::vector<unsigned int>::iterator it_insert;
    
    //Create a vector with the max value of each peer
    _vector_main.clear();
    _vector_main.reserve(len_vec_peer * 2);
    
    _vector_main.push_back(vec_peer[0].first);
    for (size_t i = 0; i < len_vec_peer; ++i)
        _vector_main.push_back(vec_peer[i].second);
    
        
    //While the jacobsthal_number is smaller than greatest index of all peer
    for (size_t i = 2; jacobsthal_number < len_vec_peer; ++i)
    {
        next_jacobsthal_number = get_jacobsthal(i + 1);
        add_idx = 0;
        
        
        // For every index between the next Jacobsthal number and the current Jacobsthal number, iterate backward.
        for (size_t j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {   

            // This condition is to prevent index out of range while next_jacobsthal_numbern is greater than _vector_main size
            if (j - 1 < len_vec_peer)
            {
                
                number_to_insert = vec_peer[j - 1].first;
                idx_upper_bound_main = j + jacobsthal_offset + add_idx;
                ++add_idx;
                   
                
                //Decreasse the upper bound until it reach the max peer
                while (_vector_main[idx_upper_bound_main] > vec_peer[j - 1].second)
                    idx_upper_bound_main--;
                
                    
                it_insert = binary_search(number_to_insert, _vector_main.begin(), _vector_main.begin() + idx_upper_bound_main);
                _vector_main.insert(it_insert, number_to_insert); 
            }    
        }
        
        jacobsthal_offset += next_jacobsthal_number - jacobsthal_number;
        jacobsthal_number = next_jacobsthal_number;
    }

    
    if (_has_last_number)
    {
        number_to_insert = _last_number;
        it_insert = binary_search(number_to_insert, _vector_main.begin(), _vector_main.end());
        _vector_main.insert(it_insert, number_to_insert);
    }
}

void PmergeMe::vector_is_sorted()
{
    for (size_t i = 1; i < _vector_main.size(); i++) {
        if (_vector_main[i - 1] > _vector_main[i]) 
        {
            std::cout << "The vector isn't sorted\n";
            std::cout << _vector_main[i - 1] << " > " << _vector_main[i] << "\n";
            std::cout << "Index: " << i << "\n";
            return;
        }
    }
    std::cout << "The vector is sorted\n";
    return;
}

void PmergeMe::print_vector()
{
    for (size_t i = 0; i < _vector_main.size(); ++i)
        std::cout << _vector_main[i] << " ";
    std::cout << "\n";
}



// ==============================
//          LIST
// ==============================

void PmergeMe::fill_list()
{   
    std::vector<unsigned int>::iterator it = _vector_main.begin();
    std::vector<unsigned int>::iterator ite = _vector_main.end();
    
    for (; it != ite; it++)
        _list_main.push_back(*it);
}


void PmergeMe::init_sort_list()
{
    std::list<std::pair<unsigned int, unsigned int> > list_peer;
    std::pair<unsigned int, unsigned int> peer;
    
    std::list<unsigned int>::iterator it = _list_main.begin();
    std::list<unsigned int>::iterator next = it;
    
    if (_list_main.size() == 1)
        return;
        
    while (it != _list_main.end() && next != _list_main.end())
    {
        next = it;
        ++next;
        
        if (*it < *next)
            peer = std::make_pair(*it, *next);
        else
            peer = std::make_pair(*next, *it);

        list_peer.push_back(peer);
        
        it = next;
        ++it;
    } 
    
    merge_sort_list(list_peer, 0, list_peer.size() -1);

    insertion_smallest_peer_list(list_peer);
}

void PmergeMe::merge_list(
    std::list<std::pair<unsigned int, unsigned int> >& arr,
    unsigned int left,
    unsigned int mid,
    unsigned int right)
{
    std::list<std::pair<unsigned int, unsigned int> > L;
    std::list<std::pair<unsigned int, unsigned int> > R;

    std::list<std::pair<unsigned int, unsigned int> >::iterator it;
    std::list<std::pair<unsigned int, unsigned int> >::iterator itL;
    std::list<std::pair<unsigned int, unsigned int> >::iterator itR;
    
    it = arr.begin();

    std::advance(it, left);

    for (unsigned int i = 0; i <= mid - left; ++i, ++it)
        L.push_back(*it);

    for (unsigned int i = 0; i < right - mid; ++i, ++it)
        R.push_back(*it);

    itL = L.begin();
    itR = R.begin();

    it = arr.begin();
    std::advance(it, left);

    while (itL != L.end() && itR != R.end())
    {
        if (itL->second <= itR->second)
            *it++ = *itL++;
        else
            *it++ = *itR++;
    }

    while (itL != L.end())
        *it++ = *itL++;

    while (itR != R.end())
        *it++ = *itR++;
}

void PmergeMe::merge_sort_list(
    std::list<std::pair<unsigned int, unsigned int> >& arr, 
    unsigned int left, 
    unsigned int right
)
{
    if (left >= right)
        return;
        
    unsigned int mid = left + (right - left) / 2;
    merge_sort_list(arr, left, mid);
    merge_sort_list(arr, mid + 1, right);
    merge_list(arr, left, mid, right);
}

void PmergeMe::insertion_smallest_peer_list(const std::list<std::pair<unsigned int, unsigned int> >& list_peer)
{   
    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int next_jacobsthal_number;
    unsigned int number_to_insert;
    
    size_t len_list_peer = list_peer.size();
    
    std::list<std::pair<unsigned int, unsigned int> >::const_iterator it_begin = list_peer.begin();
    std::list<std::pair<unsigned int, unsigned int> >::const_iterator it;
    std::list<unsigned int>::iterator it_insert;
    
    for (it = it_begin; it != list_peer.end(); ++it)
        std::cout << it->first << " " << it->second << " ";
    std::cout << "\n";
    
    //Create a vector with the max value of each peer
    _list_main.clear();
    _list_main.push_back(list_peer.begin()->first);
    for (it = it_begin; it != list_peer.end(); ++it)
        _list_main.push_back(it->second);
    
    print_list();
    
    //While the jacobsthal_number is smaller than greatest index of all peer
    for (size_t i = 2; jacobsthal_number < len_list_peer; ++i)
    {

        next_jacobsthal_number = get_jacobsthal(i + 1);

        // For every index between the next Jacobsthal number and the current Jacobsthal number, iterate backward.
        for (size_t j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {   
            
            // This condition is to prevent index out of range while next_jacobsthal_numbern is greater than _list_main size
            if (j - 1 < len_list_peer)
            {
                it = list_peer.begin();
                std::advance(it, j - 1);
                
                number_to_insert = (*it).first;
                std::cout << "Number to insert: " << number_to_insert << "\n";
                std::cout << "Max: " << (*it).second << "\n";
                std::cout << "\n";
                
                it_insert = binary_search(number_to_insert, _list_main.begin(), _list_main.end());
                _list_main.insert(it_insert, number_to_insert); 
            }    
        }
        jacobsthal_number = next_jacobsthal_number;
    }
}

void PmergeMe::list_is_sorted()
{
    std::list<unsigned int>::iterator prev = _list_main.begin();
    std::list<unsigned int>::iterator curr = prev;
    ++curr;

    size_t index = 1;

    while (curr != _list_main.end())
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

void PmergeMe::print_list()
{
    std::list<unsigned int>::iterator it = _list_main.begin();
     
    for (; it != _list_main.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}