/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:27:07 by fmotte            #+#    #+#             */
/*   Updated: 2026/02/22 19:26:51 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base() {}

// ====================
// ==   Mandatory    ==
// ====================
Base *Base::generate(void)
{
    double rand = my_random() * 3;

    if (0 < rand && rand < 1)
    {
        std::cout << "Create a class A\n";
        return new A();
    }
        
        
    if (1 < rand && rand < 2)
    {
        std::cout << "Create a class B\n";
        return new B();
    }
    
    std::cout << "Create a class C\n";
    return new C();
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*> (p) != 0)
    {
        std::cout << "Is class A\n";
        return ;
    }
    
    if (dynamic_cast<B*> (p) != 0)
    {
        std::cout << "Is class B\n";
        return ;
    }

    if (dynamic_cast<C*> (p) != 0)
    {
        std::cout << "Is class C\n";
        return ;
    }
}

void Base::identify(Base& p)
{
    try {
        (void) dynamic_cast<A&> (p);
        std::cout << "Is class A\n";
        return ;
    }
    catch(const std::exception& e){}


    try {
        (void) dynamic_cast<B&> (p);
        std::cout << "Is class B\n";
        return ;
    }
    catch(const std::exception& e){}

    try {
        (void) dynamic_cast<C&> (p);
        std::cout << "Is class C\n";
        return ;
    }
    catch(const std::exception& e){}
    
}

// ====================
// == Added Methode  ==
// ====================
Base **Base::generate_list(int nb)
{
    Base **list_base = new Base*[nb + 1];

    for (int i = 0; i < nb; i++)
        list_base[i] = generate();
    
    list_base[nb] = 0; 
    return list_base;
}

void Base::delete_list(Base **list)
{
    for (int i = 0; list[i] != 0; i++)
        delete  list[i];
        
    delete []list;
}

void Base::identify_by_ptr_list(Base **list)
{
    for (int i = 0; list[i] != 0; i++)
        identify(list[i]);
}

void Base::identify_by_ref_list(Base **list)
{
    for (int i = 0; list[i] != 0; i++)
        identify(*list[i]);
}