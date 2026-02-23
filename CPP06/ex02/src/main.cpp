/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:27:02 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/23 13:49:42 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

// dynamic_cast: Runtime-checked cast for polymorphic types.
// Used mainly for safe downcasting in class hierarchies.
// Requires at least one virtual function in the base class.
// Returns nullptr (for pointers) or throws std::bad_cast (for references) if the cast fails.

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