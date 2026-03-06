/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:04:16 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/06 14:46:05 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{   
    //Stack
    std::cout << "\nSTACK\n";
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    
    mstack.push(0);
    
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    
    //List
    std::cout << "\nList\n";
    std::list<int> list;
    
    list.push_front(5);
    list.push_front(17);

    std::cout << list.front() << std::endl;

    list.pop_front();

    std::cout << list.size() << std::endl;
    
    list.push_front(3);
    list.push_front(5);
    list.push_front(737);
    
    list.push_front(0);
    
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}


// int main()
// {   
//     //Stack
//     std::cout << "\nSTACK\n";
//     MutantStack<int> mstack;
    
//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;
    
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
    
//     mstack.push(0);
    
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
    
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
    
    
//     //List
//     std::cout << "\nList\n";
//     std::list<int> list;
    
//     list.push_back(5);
//     list.push_back(17);

//     std::cout << list.back() << std::endl;

//     list.pop_back();

//     std::cout << list.size() << std::endl;
    
//     list.push_back(3);
//     list.push_back(5);
//     list.push_back(737);
    
//     list.push_back(0);
    
//     std::list<int>::iterator lit = list.begin();
//     std::list<int>::iterator lite = list.end();
    
//     ++lit;
//     --lit;
//     while (lit != lite)
//     {
//         std::cout << *lit << std::endl;
//         ++lit;
//     }
//     return 0;
// }