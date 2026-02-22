/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:27:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/22 17:17:02 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int main()
{   
    //Initiaze pseudo-random number generator using the current time since the 1er janvier 1970 (timestamp Unix)
    //Need for the class RobotomyRequestForm
    std::srand(std::time(0));

    Base base;
    Base **list;

    list = base.generate_list(10);
    
    std::cout << "\nIdentify by pointer\n";
    base.identify_by_ptr_list(list);
    
    std::cout << "\nIdentify by reference\n";
    base.identify_by_ref_list(list);

    base.delete_list(list);
    
    return 0;
}