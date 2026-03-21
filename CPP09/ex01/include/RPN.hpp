/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:49 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/21 16:38:02 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <stack>
# include <limits>
# include <cstdlib>

class RPN
{
    private:
        
        static const std::string _allowed_operation;    
        static std::stack<int> _st;
        
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        
    public:
    
        static std::string get_allowed_operation();
        
        static void calcul(std::string string);
        
        static bool do_operation(char operation);

        static bool apply_add(const int &a, const int &b, int &res);
        static bool apply_minus(const int &a, const int &b, int &res);
        static bool apply_mul(const int &a, const int &b, int &res);
        static bool apply_div(const int &a, const int &b, int &res);

        static void remove_white_space(std::string& string);
};


