/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:56:25 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/12 14:48:04 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

# include "iter.hpp"

void my_print_char(const char c){std::cout << c;}
void my_print_int(const int i){std::cout << i << " ";}
void next_char(char &c) {c += 1;}
void put_squarre(int &i) {i *= i;}

int main()
{
    
    
    //Const Tab String with const func
    std::string test1 =  "hello world";
    iter(test1.c_str(), test1.length(), my_print_char);      
    std::cout << "\n\n";


    //Non-const Tab String with non-const func
    std::string test2 =  "abcdef";
    std::cout << "Before: " << test2 << "\n";
    iter(&test2[0], test2.length(), next_char);         
    std::cout << "After: " << test2 << "\n";


    std::cout << "\n";
    int test3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Before: ";
    //Non-const Tab Int with const func   
    iter(test3, 11, my_print_int);  
        
    //Non-const Tab Int with non-const func    
    iter(&test3[0], 11, put_squarre);                   
    
    std::cout << "\nAfter:  ";
    //Non-const Tab Int with const func  
    iter(test3, 11, my_print_int); 

    //Check Ptr NULL    
    int *ptr_null =  NULL;
    iter(ptr_null, 11, put_squarre);                    

    //Check Func NULL
    void (*func_null)(int &i) = NULL;
    iter(&test3[0], 11, func_null);                     
}