/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:49 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/09 18:15:37 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <stack>
# include <sstream>
# include <limits>
#include <cstring>

class RPN
{
    private:

        static const std::string _allowed_operation;    
        std::stack<std::string> _st;
        
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        std::string get_allowed_operation();
        
        void fill(int argc, char **argv);
        bool calcul();

        bool apply_add(const int &a, const int &b, int &res);
        bool apply_minus(const int &a, const int &b, int &res);
        bool apply_muly(const int &a, const int &b, int &res);
        bool apply_div(const int &a, const int &b, int &res);

        bool check_overflow(const long &a);
        bool check_underflow(const long &a);
};


