/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:23 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 15:25:30 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void try_catch_add(Span &sp, int number)
{
    try
    {
        sp.addNumber(number);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void try_catch_constructor(int number)
{
    try
    {
        Span sp(number);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test1()
{
    //Span with len 0
    std::cout << "\n------------------\n";
    std::cout << "Span with len 0\n";
    Span sp1(0);
    std::cout << sp1 << "\n";
    
    try_catch_add(sp1, 1);
    std::cout << sp1 << "\n";


    //Span with len 1
    std::cout << "\n------------------\n";
    std::cout << "Span with len -1\n";
    try_catch_constructor(-1);
    
    
    //Span with len LEN_MAX + 1
    std::cout << "\n------------------\n";
    std::cout << "Span with len LEN_MAX + 1\n";
    try_catch_constructor(LEN_MAX + 1);
    
    
    //Span with len LEN_MAX
    std::cout << "\n------------------\n";
    std::cout << "Span with len LEN_MAX\n";
    Span sp3(LEN_MAX);
    std::cout << sp3 << "\n";
    try_catch_add(sp3, INT_MAX);
    std::cout << sp3 << "\n";
    try_catch_add(sp3, INT_MIN);
    std::cout << sp3 << "\n";


    //Span with len 4
    std::cout << "\n------------------\n";
    std::cout << "Span with len 4\n";
    Span sp4(4);
    std::cout << sp4 << "\n";

    try_catch_add(sp4, 1);
    std::cout << sp4 << "\n";
    
    try_catch_add(sp4, 2);
    try_catch_add(sp4, 3);
    try_catch_add(sp4, 4);
    std::cout << sp4 << "\n";

    try_catch_add(sp4, 5);
    std::cout << sp4 << "\n";
}

void test2()
{

}

int main()
{
    test1();

    return (0);
}