/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florent <florent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:12:40 by florent           #+#    #+#             */
/*   Updated: 2026/01/07 21:51:12 by florent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

/*PUBLIC*/
Account::Account (int initial_deposit): _nbDeposits(initial_deposit)
{
    this->_accountIndex = 0;
    this->_amount = 0;
    this->_nbAccounts = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount = 0;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
}

Account::~Account(void) {}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return(_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    std::cout << "Hello World" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_nbAccounts = deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal != 0)
        return (1);
    return (0);
}

int	Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    std::cout << "Status" << std::endl;
}

/*PRIVATE*/
void Account::_displayTimestamp(void)
{
    std::cout << "Tmestamp" << std::endl;
}

Account::Account (void)
{
    this->_accountIndex = 0;
    this->_amount = 0;
    this->_nbAccounts = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount = 0;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
}