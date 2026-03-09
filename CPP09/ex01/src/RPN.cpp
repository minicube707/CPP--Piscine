/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/09 18:18:11 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

const std::string RPN::_allowed_operation =  "+ - / *";

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& other){*this = other;}
RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _st = other._st;
    return *this;
}

void RPN::fill(int argc, char **argv)
{
    for(int i = argc-1; i > 0; i--)
    {
        if (std::strlen(argv[i]) != 1)
        {
            //print error
            //return true
        }
        if (std::isdigit(static_cast<unsigned char>(argv[i][0]))) // ou in allowed_char
            _st.push(argv[i]);
        else
            //print error
            //return true
    }
}

std::string RPN::get_allowed_operation() {return _allowed_operation;}

bool RPN::calcul()
{  
    std::string tab_string[2];
    std::string operation;
    std::string allowed_operation =  get_allowed_operation();
    
    int tab_int[2];
    int res;
    
    bool (RPN::*lis_apply_func[4])(const int &a, const int &b, int &res) = 
    {
        &RPN::apply_add, 
        &RPN::apply_minus, 
        &RPN::apply_muly,
        &RPN::apply_div
    };
    
    //Three first element of the stack
    tab_string[0] = _st.top();
    _st.pop();
    tab_string[1] = _st.top();
    _st.pop();
    operation = _st.top();

    std::cout << tab_string[0] << "  " << tab_string[1] << "  " << operation << "\n";

    
    for (int i = 0; i < 2; i++)
    {
        std::istringstream iss(tab_string[i]);
        iss >> tab_int[i];

        if (iss.fail() || !iss.eof())
            return true;
    }
    
    for (int  i = 0; i < allowed_operation.length(); i++)
    {
        if (operation[0] == allowed_operation[i] && operation.length() == 1)
        {
            if ((this->*lis_apply_func[i])(tab_int[0], tab_int[1], res))
                return true;    
        }
            
    }
}


bool RPN::apply_add(const int &a, const int &b, int &res) 
{   
    if (check_overflow(a + b))
        return true;
    
    if (check_underflow(a + b))
        return true;
        
    res = a + b;
    return false;
}

bool RPN::apply_minus(const int &a, const int &b, int &res)
{   
    
    if (check_overflow(a - b))
        return true;
        
    if (check_underflow(a - b))
        return true;
        
    res = a - b;
    return false;
}

bool RPN::apply_muly(const int &a, const int &b, int &res)
{
    if (check_overflow(a * b))
        return true;

    if (check_underflow(a - b))
        return true;
    
    res = a * b;
    return false;
}

bool RPN::apply_div(const int &a, const int &b, int &res)
{
    if (b == 0)
    {
        std::cerr << "Error: division by 0 impossible\n";
        return true;
    }
    
    if (check_overflow(a / b))
        return true;

    if (check_underflow(a / b))
        return true;

    res = a / b;
    return false;
}


bool RPN::check_overflow(const long &a)
{
    if (a > std::numeric_limits<int>::max())
    { 
        std::cerr << "Error: overflow\n";
        return true;
    }
    return false;
}

bool RPN::check_underflow(const long &a)
{
    if (a < std::numeric_limits<int>::min())
    { 
        std::cerr << "Error: underflow\n";
        return true;
    }
    return false;
}