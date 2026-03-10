/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:53 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/10 16:57:28 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"
#include <cassert>

int main(int argc, char **argv)
{
    (void) argv;
    if (argc < 2)
    {
        std::cout << "Error: too fewer elements\n";
        return (1);
    }
    
    if (argc > 2)
    {
        std::cout << "Error: too much elements\n";
        return (1);
    }
    
    RPN::calcul(argv[1]);
}


// int main() {
//     int res;

//     // ======================
//     // TEST ADDITION
//     // ======================
//     // Cas normal
//     assert(RPN::apply_add(10, 5, res) == false && res == 15);
//     assert(RPN::apply_add(-10, -5, res) == false && res == -15);

//     // Overflow
//     assert(RPN::apply_add(std::numeric_limits<int>::max(), 1, res) == true);

//     // Underflow
//     assert(RPN::apply_add(std::numeric_limits<int>::min(), -1, res) == true);

//     std::cout << "Addition tests passed ✅\n";

//     // ======================
//     // TEST SUBTRACTION
//     // ======================
//     assert(RPN::apply_minus(10, 5, res) == false && res == 5);
//     assert(RPN::apply_minus(-10, -5, res) == false && res == -5);

//     // Overflow / underflow
//     assert(RPN::apply_minus(std::numeric_limits<int>::max(), -1, res) == true);
//     assert(RPN::apply_minus(std::numeric_limits<int>::min(), 1, res) == true);

//     std::cout << "Subtraction tests passed ✅\n";

//     // ======================
//     // TEST MULTIPLICATION
//     // ======================
//     assert(RPN::apply_mul(10, 5, res) == false && res == 50);
//     assert(RPN::apply_mul(-10, -5, res) == false && res == 50);
//     assert(RPN::apply_mul(-10, 5, res) == false && res == -50);
//     assert(RPN::apply_mul(0, 12345, res) == false && res == 0);

//     // Overflow / underflow
//     assert(RPN::apply_mul(std::numeric_limits<int>::max(), 2, res) == true);
//     assert(RPN::apply_mul(std::numeric_limits<int>::min(), 2, res) == true);

//     std::cout << "Multiplication tests passed ✅\n";

//     // ======================
//     // TEST DIVISION
//     // ======================
//     assert(RPN::apply_div(10, 2, res) == false && res == 5);
//     assert(RPN::apply_div(-10, -2, res) == false && res == 5);
//     assert(RPN::apply_div(-10, 2, res) == false && res == -5);

//     // Division by zero
//     assert(RPN::apply_div(10, 0, res) == true);

//     // Overflow case INT_MIN / -1
//     assert(RPN::apply_div(std::numeric_limits<int>::min(), -1, res) == true);

//     std::cout << "Division tests passed ✅\n";

//     std::cout << "All tests passed successfully 🎉\n";

//     return 0;
// }