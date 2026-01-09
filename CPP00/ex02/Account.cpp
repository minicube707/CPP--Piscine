/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmotte <fmotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:12:40 by florent           #+#    #+#             */
/*   Updated: 2026/01/09 13:49:42 by fmotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

/*PUBLIC*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account (int initial_deposit): _amount(initial_deposit)
{
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created"  << "\n";
    
    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << "\n";    
}

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
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::makeDeposit(int deposit)
{
    int previous_amount;
    
    previous_amount = _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << previous_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" <<  _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previous_amount;
    previous_amount = _amount;
    
    if (withdrawal < _amount)
    {    
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << previous_amount << ";";
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" <<  _amount << ";";
        std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
        
        return (1);
    }
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << previous_amount << ";";
    std::cout << "withdrawal:refused" << "\n";
    
    return (0);
}

int	Account::checkAmount(void) const
{
    _displayTimestamp();
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << "\n"; 
}

/*PRIVATE*/
void Account::_displayTimestamp(void)
{
    // std::cout << "[19920104_091532] ";

    time_t timestamp = time(NULL);
    struct tm * timeInfos = localtime(&timestamp);
    
    std::cout << "[";
    std::cout << std::setw(4) << std::setfill('0') << timeInfos->tm_year+1900;
    std::cout << std::setw(2) << std::setfill('0') << timeInfos->tm_mon+1;
    std::cout << std::setw(2) << std::setfill('0') << timeInfos->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << timeInfos->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << timeInfos->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << timeInfos->tm_sec;
    std::cout << "] ";    
}

Account::Account (void)
{
    _accountIndex = 0;
    _amount = 0;
    _nbAccounts = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount = 0;
    _totalNbDeposits = 0;
    _totalNbWithdrawals = 0;
}