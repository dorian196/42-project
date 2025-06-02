/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:54:40 by dpascal           #+#    #+#             */
/*   Updated: 2025/05/26 07:54:41 by dpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    this->_accountIndex = Account::_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";created" << std::endl;

    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
    Account::_nbAccounts -= 1;
    Account::_totalAmount -= this->_amount;
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout
        << "accounts:" << Account::getNbAccounts()
        << ";total:" << Account::getTotalAmount()
        << ";deposits:" << Account::getNbDeposits()
        << ";withdrawals:" << Account::getNbWithdrawals()
        << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount
        << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout
        << ";amount:" << this->_amount
        << ";nb_deposits:" << this->_nbDeposits
        << std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";p_amount:" << this->_amount;
    if (withdrawal > this->checkAmount())
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    std::cout << ";withdrawal:" << withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    std::cout
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << std::endl;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";amount:" << this->_amount
        << ";deposits:" << this->_nbDeposits
        << ";withdrawals:" << this->_nbWithdrawals
        << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm* ptm = std::localtime(&now);
    std::cout
        << "["
        << std::setfill('0') << std::setw(4) << (ptm->tm_year + 1900)
        << std::setw(2) << (ptm->tm_mon + 1)
        << std::setw(2) << ptm->tm_mday
        << "_"
        << std::setw(2) << ptm->tm_hour
        << std::setw(2) << ptm->tm_min
        << std::setw(2) << ptm->tm_sec
        << "] ";
}
