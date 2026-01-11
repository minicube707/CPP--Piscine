/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:59:11 by fmotte            #+#    #+#             */
/*   Updated: 2026/01/11 18:21:30 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{   
    std::string string = "HI THIS IS BRAIN";
    std::cout << "String initial: " << string << std::endl;

    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "\nHello, my name is stringPTR, I am a pointer. I store an address and can exist on its own." << std::endl;
    std::cout << "Hello, my name is stringREF, I am a reference. I am an alias and must be bound to an existing variable." << std::endl;
    
    std::cout << "\nRaw variables" << std::endl;
    std::cout << "Variable  (string):    " << string << std::endl;
    std::cout << "Pointer   (stringPTR): " << stringPTR << std::endl;
    std::cout << "Reference (stringREF): " << stringREF << std::endl;

    std::cout << "\nAdresses variables" << std::endl;
    std::cout << "Variable  (&string):    " << &string << std::endl;
    std::cout << "Pointer   (&stringPTR): " << &stringPTR << std::endl;
    std::cout << "Reference (&stringREF): " << &stringREF << std::endl;

    std::cout << "\nPointed values" << std::endl;
    std::cout << "Variable  (string):     " << string << std::endl;
    std::cout << "Pointer   (*stringPTR): " << *stringPTR << std::endl;
    std::cout << "Reference (stringREF):  " << stringREF << std::endl;
    return (0);
}