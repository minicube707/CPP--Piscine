/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:53 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/09 15:13:22 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int main(int argc, char **argv)
{
    (void) argv;
    if (argc < 2)
    {
        std::cout << "Error: too fewer elements\n";
        return (1);
    }
    
    if (argc > 10)
    {
        std::cout << "Error: too much elements\n";
        return (1);
    }
    
    RPN rpn;

    rpn.fill(argc, argv);
    rpn.calcul();
}