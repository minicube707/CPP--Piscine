/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:23 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/25 18:37:12 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
This is not the official version of project ex01 that will be evaluated.
This is simply my own implementation of the project.
*/

void try_catch_short(Span &sp)
{
    try
    {
        std::cout << "Shorthest Span: " << sp.shortestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void try_catch_long(Span &sp)
{
    try
    {
        std::cout << "Longest Span: " << sp.longestSpan() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

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

void test0()
{
    Span sp(4);
    std::cout << sp << "\n";
    try_catch_add(sp, 1);
    try_catch_add(sp, 2);
    try_catch_add(sp, 3);
    try_catch_add(sp, 4);
    std::cout << sp << "\n";

    Span spc(sp);
    std::cout << spc << "\n";

    Span spa = sp;
    std::cout << spa << "\n";
}

void test1()
{
    std::srand(std::time(0));
        
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
    Span sp1(10);
    std::cout << sp1 << "\n";
    sp1.addNumber(std::rand());
    Span sp5(10000);
    std::cout << sp5 << "\n";
    for (unsigned int i = 0; i < sp5.get_max_size(); i++)
        sp5.addNumber(std::rand());
    std::cout << sp5 << "\n";
    
    std::cout << "\n";
    try_catch_short(sp5);
    try_catch_long(sp5);
}

int main()
{
    test0();
    test1();
    test2();
    
    return (0);
}