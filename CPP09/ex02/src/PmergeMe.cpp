/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:04:17 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/18 19:28:32 by fmotte           ###   ########.fr       */
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
        _vector = other._vector;
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
    
    for (int i = 1 ; i < argc - 1; i++)
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

void PmergeMe::init_sort_vector()
{
    std::vector<std::pair<unsigned int, unsigned int> > vec_peer;
    std::pair<unsigned int, unsigned int> peer;
    
    for (size_t i = 0; i < _vector.size() - 1; i += 2)
    {
        if (_vector[i] < _vector[i + 1])
            peer = std::make_pair(_vector[i], _vector[i + 1]);
        else
            peer = std::make_pair(_vector[i + 1], _vector[i]);
            
        vec_peer.push_back(peer);
    } 
    
    if (_vector.size() % 2 == 1)
    {
        _has_last_number = true;
        _last_number = *(_vector.end() -1);
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

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
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
    std::vector<unsigned int> vec_cpy;
    std::vector<unsigned int> vec_add_index;
    
    unsigned int jacobsthal_number = get_jacobsthal(2);
    unsigned int next_jacobsthal_number;
    unsigned int min_number;
    unsigned int upper_bound;
    unsigned int test;
    
    std::vector<unsigned int>::iterator it_insert;
    
    for (unsigned int i = 0; i <= vec_peer.size() - 1; ++i)
    {
        vec_cpy.push_back(vec_peer[i].first);
        vec_cpy.push_back(vec_peer[i].second);;
    }
    
    std::cout << "\n";
    for (unsigned int i = 0; i <= vec_cpy.size() - 1; ++i)
        std::cout << vec_cpy[i] << " ";
    std::cout << "\n";
    
    //Create a vector with the max value of each peer
    _vector.clear();
    _vector.push_back(vec_cpy[0]);
    for (unsigned int i = 1; i <= vec_cpy.size(); i += 2)
        _vector.push_back(vec_cpy[i]);
    vec_add_index.assign(_vector.size(), 0);

    //While the jacobsthal_number is smaller than greatest index of all peer
    for (unsigned int i = 2; jacobsthal_number < vec_cpy.size(); ++i)
    {
        next_jacobsthal_number = get_jacobsthal(i + 1);
        
        // For every index between the next Jacobsthal number and the current Jacobsthal number, iterate backward.
        for (unsigned int j = next_jacobsthal_number; j > jacobsthal_number; --j)
        {   
            
            // This condition is to prevent index out of range while next_jacobsthal_numbern is greater than _vector size
            if ((j - 1) * 2 < vec_cpy.size())
            {
                std::cout << "\n";
                print_vector();
            
                min_number = vec_cpy[(j - 1) * 2];
                upper_bound = (j - 1) * 2 + 1;
                test = j + i - 2;
            
                std::cout << "inser num: " << min_number << "\n";
                std::cout << "upper boud: " << upper_bound << "\n";
                std::cout << "the max: " << vec_cpy[upper_bound] << "\n";
                std::cout << "My max:  " << _vector[test] << "\n";
                
                std::cout << "\nthe index: " << find(_vector.begin(), _vector.end(), vec_cpy[upper_bound]) - _vector.begin()<< "\n";
                std::cout << "My index:   " << test << "\n";
                std::cout << "Add index:  " << vec_add_index[upper_bound] << "\n";
                std::cout << "Se index:   " << test + vec_add_index[upper_bound] << "\n";
                
                it_insert = binary_search(min_number, _vector.begin(), _vector.end());
                _vector.insert(it_insert, min_number); 
                
                vec_add_index.push_back(*(vec_add_index.end() - 1));
                for (unsigned int i = it_insert - _vector.begin(); i < vec_add_index.size(); i++)
                    vec_add_index[i]++;
                    
                std::cout << "Vector index\n";
                for (unsigned int i = 0; i < vec_add_index.size(); i++)
                    std::cout << vec_add_index[i] << " ";
                std::cout << "\n";
                std::cout << "\n";
            }    
        } 
        jacobsthal_number = next_jacobsthal_number;
    }

    if (_has_last_number)
    {
        min_number = _last_number;
        it_insert = binary_search(min_number, _vector.begin(), _vector.end());
        _vector.insert(it_insert, min_number);
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
    for (size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << "\n";
}
