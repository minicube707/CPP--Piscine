/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:25 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/24 14:00:35 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

# include "iter.hpp"

void my_print(const char c){std::cout << c;}
void next_char(char &c) {c += 1;}
void put_squarre(int &i) {i *= i;}

int main()
{
    std::string test1 =  "hello world";
    iter(test1.c_str(), test1.length(), my_print);      //Const Tab String
    
    std::cout << "\n\n";
    std::string test2 =  "abcdef";
    
    std::cout << "Before: " << test2 << "\n";
    iter(&test2[0], test2.length(), next_char);         //Non-const Tab String
    std::cout << "After: " << test2 << "\n";


    std::cout << "\n";
    int test3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Before: ";
    for (int i = 0; i < 11; i++)
        std::cout << test3[i] << " ";
        
    iter(&test3[0], 11, put_squarre);                   //Non-const Tab Int
    
    std::cout << "\nAfter:  ";
        for (int i = 0; i < 11; i++)
        std::cout << test3[i] << " ";

    int *ptr_null =  NULL;
    iter(ptr_null, 11, put_squarre);                    //Check Ptr NULL

    void (*func_null)(int &i) = NULL;
    iter(&test3[0], 11, func_null);                     //Check Func NULL
}