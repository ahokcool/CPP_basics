/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:14:04 by astein            #+#    #+#             */
/*   Updated: 2024/03/02 17:47:57 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) {}	
Account::~Account( void ) {}

int	Account::getNbAccounts( void )		{ return Account::_nbAccounts;			}
int	Account::getTotalAmount( void )		{ return Account::_totalAmount;			}
int	Account::getNbDeposits( void )		{ return Account::_totalNbDeposits;		}
int	Account::getNbWithdrawals( void )	{ return Account::_totalNbWithdrawals;	}
 
void	Account::displayAccountsInfos( void )
{
	std::cout << "display accounts infos" << std::endl;	
}

void	Account::_displayTimestamp( void )
{
	char formated[50];
	
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	strftime(formated, sizeof(formated), "[%Y%m%d_%H%M%S]", now);
	std::cout << formated << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	std::cout << "make deposit" + deposit << std::endl;	
}

bool	Account::makeWithdrawal( int withdrawal )
{
	std::cout << "make withdrawal" + withdrawal << std::endl;
	return true;	
}

int		Account::checkAmount( void ) const
{
	std::cout << "check amount" << std::endl;
	return 0;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "display status" << std::endl;
}
