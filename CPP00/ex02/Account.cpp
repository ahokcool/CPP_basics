/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:14:04 by astein            #+#    #+#             */
/*   Updated: 2024/03/02 18:53:29 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// =============================================================================
// 		Non member functions
// =============================================================================

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )		{ return Account::_nbAccounts;			}
int	Account::getTotalAmount( void )		{ return Account::_totalAmount;			}
int	Account::getNbDeposits( void )		{ return Account::_totalNbDeposits;		}
int	Account::getNbWithdrawals( void )	{ return Account::_totalNbWithdrawals;	}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" << _nbAccounts 
		<< ";total:" << getTotalAmount() 
		<< ";deposits:" << getNbDeposits() 
		<< ";withdrawals:" << getNbWithdrawals() 
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	char formated[50];
	
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	strftime(formated, sizeof(formated), "[%Y%m%d_%H%M%S] ", now);
	std::cout << formated;
}

// =============================================================================
// 		Member functions
// =============================================================================

// Constructor
Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
	<< std::endl;
}

// Destructor
Account::~Account( void )
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed"
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int old_amount = _amount;
	
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << old_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
	<< std::endl;	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int old_amount = _amount;
	
	if (checkAmount() < withdrawal)
	{
		_displayTimestamp();
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
		<< std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << old_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
		return true;	
	}	
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}
