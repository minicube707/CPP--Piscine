/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:05:42 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 13:16:56 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <set>
#include <stack>
#include <deque>

#include <iostream>

#include "easyfind.hpp"

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    
    std::cout << "\nVerctor:\n";
    std::vector<int> v(arr, arr + 9);
    std::cout << (easyfind(v, 1) ? "" : "not") << "find\n";
    std::cout << (easyfind(v, 9) ? "" : "not") << "find\n";
    std::cout << (easyfind(v, 10) ? "" : "not") << "find\n";
    std::cout << (easyfind(v, -1) ? "" : "not") << "find\n";


    std::cout << "\nList:\n";
    std::list<int> l;
    for (int i = 0; i < 9; i++)
        l.push_back(arr[i]);
    std::cout << (easyfind(l, 1) ? "" : "not") << "find\n";
    std::cout << (easyfind(l, 9) ? "" : "not") << "find\n";
    std::cout << (easyfind(l, 10) ? "" : "not") << "find\n";
    std::cout << (easyfind(l, -1) ? "" : "not") << "find\n";

    
    std::cout << "\nSet:\n";
    std::set<int> se(arr, arr + 9);
    std::cout << (easyfind(se, 1) ? "" : "not") << "find\n";
    std::cout << (easyfind(se, 9) ? "" : "not") << "find\n";
    std::cout << (easyfind(se, 10) ? "" : "not") << "find\n";
    std::cout << (easyfind(se, -1) ? "" : "not") << "find\n";


    std::cout << "\nStack:\n";
    std::set<int> st(arr, arr + 9);
    std::cout << (easyfind(st, 1) ? "" : "not") << "find\n";
    std::cout << (easyfind(st, 9) ? "" : "not") << "find\n";
    std::cout << (easyfind(st, 10) ? "" : "not") << "find\n";
    std::cout << (easyfind(st, -1) ? "" : "not") << "find\n";

    
    std::cout << "\nDequeue:\n";
    std::deque<int> d;
    for (int i = 0; i < 9; i++)
        d.push_back(arr[i]);
    std::cout << (easyfind(d, 1) ? "" : "not") << "find\n";
    std::cout << (easyfind(d, 9) ? "" : "not") << "find\n";
    std::cout << (easyfind(d, 10) ? "" : "not") << "find\n";
    std::cout << (easyfind(d, -1) ? "" : "not") << "find\n";

}