/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frite <frite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:34:26 by frite             #+#    #+#             */
/*   Updated: 2024/09/24 17:56:00 by frite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//////////Constructor//////////

Account::Account(int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0){
    this->_amount = initial_deposit;
    Account::_totalAmount += this->_amount;
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
}

//////////Destructor//////////

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

//////////////////////////////

void	Account::_displayTimestamp( void )
{
	time_t now = std::time(NULL);
	struct tm timenow = *std::localtime(&now);

	std::cout << "[" << timenow.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << timenow.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << timenow.tm_hour <<
	std::setfill('0') << std::setw(2) << timenow.tm_min <<
	std::setfill('0') << std::setw(2) << timenow.tm_sec <<
	"] ";
	//for diff between log files use line below
	//std::cout << "[19920104_091532] ";
}

//////////Geters//////////

int Account::getNbAccounts(void){
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void){
	return Account::_totalAmount;
}

int Account::getNbDeposits(void){
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	return Account::_totalNbWithdrawals;
}

//////////////////////////////

void	Account::displayAccountsInfos(void){
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl; 
}

//////////////////////////////

void	Account::makeDeposit(int deposit){
    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit;
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	if (this->checkAmount() < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}	
}

int	Account::checkAmount(void) const{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
