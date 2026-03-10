/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:20:51 by fmotte            #+#    #+#             */
/*   Updated: 2026/03/10 16:58:45 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

const std::string RPN::_allowed_operation =  "+-/*";
std::stack<int> RPN::_st;

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN& other){*this = other;}
RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _st = other._st;
    return *this;
}

void RPN::calcul(std::string string)
{
    std::string allowed_operation = get_allowed_operation();
    
    remove_white_space(string);
    
    while (!string.empty())
    {
        
        if (std::isdigit((string[0])) && std::isdigit((string[1])))
        {
            std::cerr << "Error: Wrong accept only digit between 0 and 9\n";
            return;
        }
        
        else if (std::isdigit((string[0])))
            _st.push(std::atoi(&string[0]));

        
        else if (allowed_operation.find(string[0]) != std::string::npos)
        {
            if (do_operation(string[0]))
                return;
        }
        else
        {
            std::cerr << "Error: Wrong char accept only digit and " << allowed_operation << "\n";
            return;
        }
        string.erase(string.begin());
        remove_white_space(string);
        
    }
    
    //Reverse stack
    std::stack<int> tmp;
    while (!_st.empty())
    {
        tmp.push(_st.top());
        _st.pop();
    }
    
    //Resultat
    while (!tmp.empty())
    {
        std::cout << tmp.top() << " ";
        tmp.pop();
    }
    std::cout <<  "\n";
}

std::string RPN::get_allowed_operation() {return _allowed_operation;}


bool RPN::do_operation(char operation)
{  
    std::string allowed_operation =  get_allowed_operation();
    
    int tab_int[2];
    int res;
    
    bool (*lis_apply_func[4])(const int &a, const int &b, int &res) = 
    {
        &RPN::apply_add, 
        &RPN::apply_minus, 
        &RPN::apply_div,
        &RPN::apply_mul
    };
    
    if (_st.size() < 2)
    {
        std::cerr << "Error: miss a number to do the operation\n";
        return true; 
    }

    tab_int[1] = _st.top();
    _st.pop();
    tab_int[0] = _st.top();
    _st.pop();

    std::cout << "Operation: "<<tab_int[0] << " " << tab_int[1] << " " << operation << "\n";
    
    for (size_t  i = 0; i < allowed_operation.length(); i++)
    {
        if (operation == allowed_operation[i])
        {
            if ((*lis_apply_func[i])(tab_int[0], tab_int[1], res))
                return true;    
            break;
        }   
    }
    _st.push(res);
    return false; 
}


bool RPN::apply_add(const int &a, const int &b, int &res)
{ 

    if (b > 0 && a > std::numeric_limits<int>::max() - b)
    {
        std::cerr << "Error: overflow\n";
        return true;
    }
    
    if (b < 0 && a < std::numeric_limits<int>::min() - b)
    {
        std::cerr << "Error: underflow\n";
        return true;
    }
        
    res = a + b;
    return false;
}

bool RPN::apply_minus(const int &a, const int &b, int &res)
{
    if (b < 0 && a > std::numeric_limits<int>::max() + b)
    {
        std::cerr << "Error: overflow\n";
        return true;
    } 

    if (b > 0 && a < std::numeric_limits<int>::min() + b)
    {
        std::cerr << "Error: underflow\n";
        return true;
    }
        
    res = a - b;
    return false;
}

bool RPN::apply_mul(const int &a, const int &b, int &res)
{
    if (a == 0 || b == 0)
    {
        res = 0;
        return false;
    }

    if (a > 0)
    {
        if (b > 0 && a > std::numeric_limits<int>::max() / b) {
            std::cerr << "Error: overflow\n";
            return true;
        }
        if (b < 0 && b < std::numeric_limits<int>::min() / a) {
            std::cerr << "Error: underflow\n";
            return true;
        }
    }
    else if (a < 0)
    {
        if (b > 0 && a < std::numeric_limits<int>::min() / b) {
            std::cerr << "Error: underflow\n";
            return true;
        }
        if (b < 0 && a < std::numeric_limits<int>::max() / b) {
            std::cerr << "Error: overflow\n";
            return true;
        }
    }

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
    
    if (a == std::numeric_limits<int>::min() && b == -1)
    {
        std::cerr << "Error: overflow\n";
        return true;
    }
        
    res = a / b;
    return false;
}


bool RPN::check_overflow(const int &a, const int &b)
{
    if (a > b)
    { 
        std::cerr << "Error: overflow\n";
        return true;
    }
    return false;
}

bool RPN::check_underflow(const int &a, const int &b)
{
    if (a < b)
    { 
        std::cerr << "Error: underflow\n";
        return true;
    }
    return false;
}

void RPN::remove_white_space(std::string& string)
{
    while ((string[0] == ' ' || string[0] == '\t'))
        string.erase(string.begin());
}