/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:43:09 by uercan            #+#    #+#             */
/*   Updated: 2023/03/29 13:43:33 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )//[19920104_091532] index:0;amount:42;created
{
	// _displayTimestamp();
	// std::cout << " index:" << initial_deposit
	// << ";amount:" << _amount
	// << ";created";
	_accountIndex = getNbAccounts();// Adding +1 for every account.
	_amount = initial_deposit;// This parameter adding first creating moment.
	_nbDeposits = 0;// Initializing here all variables.
	_nbWithdrawals = 0;// Initializing
	_displayTimestamp();// Printing time.
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";created" << std::flush << std::endl;
	_totalAmount += initial_deposit;// For calculate total amount.
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << &index << ";amount:" 
	<< _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)//para çekme
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals<< std::endl;
}

void	_displayTimestamp( void )
{
	std::time_t	time;

	time = std::time(NULL);
	std::cout << std::setfill('0') << "["
		<< std::setw(2) << 1900 + std::localtime(&time)->tm_year
		<< std::setw(2) << 1 +  std::localtime(&time)->tm_mon
		<< std::setw(2) << std::localtime(&time)->tm_mday << "_"
		<< std::setw(2) << std::localtime(&time)->tm_hour
		<< std::setw(2) << std::localtime(&time)->tm_min
		<< std::setw(2) << std::localtime(&time)->tm_sec
		<< "] " << std::flush;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposits:" << deposit
	<< ";amount:" << _amount + deposit
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

// bool	Account::makeWithdrawal( int withdrawal )
// {

// }

// int		Account::checkAmount( void ) const
// {

// }

// void	Account::displayStatus( void ) const
// {

// }

void	Account::displayStatus(void) const
{
	_displayTimestamp();// Printing time.
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "deposits:" << _nbDeposits << ";" << std::flush;
	std::cout << "withdrawals:" << _nbWithdrawals << std::flush << std::endl;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << _amount << ";" << std::flush;// previous amount
	if (withdrawal <= _amount && withdrawal > 0)
	{
		getNbWithdrawals();
		std::cout << "withdrawal:" << withdrawal << ";" << std::flush;
		std::cout << "amount:" << _amount - withdrawal << ";" << std::flush;
		std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::flush << std::endl;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		return (true);// 1
	}
	std::cout << "refused" << std::flush << std::endl;
	return (false);// 0
}

int		Account::checkAmount(void) const
{
	std::cout << "checkAmount" << std::flush << std::endl;
	return (0);
}


// #include "Account.hpp"
// #include <iostream>
// // #include <ctime>
// #include <iomanip>//setw(), setfill()

// # define BLACK		"\033[0;30m"
// # define RED		"\033[0;31m"
// # define GREEN		"\033[0;32m"
// # define YELLOW		"\033[0;33m"
// # define BLUE		"\033[0;34m"
// # define PURPLE		"\033[0;35m"
// # define CYAN		"\033[0;36m"
// # define WHITE		"\033[0;37m"
// # define END		"\033[m"
// # define RESET		"\033[0m"

// int	Account::_nbAccounts = 0;
// int	Account::_totalAmount = 0;
// int	Account::_totalNbDeposits = 0;
// int	Account::_totalNbWithdrawals = 0;

// Account::Account(int initial_deposit)
// {
// 	_accountIndex = getNbAccounts();// Adding +1 for every account.
// 	_amount = initial_deposit;// This parameter adding first creating moment.
// 	_nbDeposits = 0;// Initializing here all variables.
// 	_nbWithdrawals = 0;// Initializing
// 	_displayTimestamp();// Printing time.
// 	std::cout << "index:" << _accountIndex << ";" << std::flush;
// 	std::cout << "amount:" << _amount << ";created" << std::flush << std::endl;
// 	_totalAmount += initial_deposit;// For calculate total amount.
// }

// Account::~Account(void)
// {
// 	_displayTimestamp();// Printing time.
// 	std::cout << "index:" << _accountIndex << ";" << std::flush;
// 	std::cout << "amount:" << _amount << ";closed" << std::flush << std::endl;
// }

// /**
//  * @brief Get account's count.
//  * 
//  * @return int 
//  */
// int	Account::getNbAccounts(void)
// {
// 	return (_nbAccounts++);
// }

// int	Account::getTotalAmount(void)
// {
// 	return (_totalAmount);
// }

// int	Account::getNbDeposits(void)
// {
// 	return (_totalNbDeposits++);
// }

// int	Account::getNbWithdrawals(void)
// {
// 	return (_totalNbWithdrawals++);
// }

// void	Account::displayAccountsInfos(void)
// {
// 	_displayTimestamp();
// 	std::cout << GREEN << "accounts:" << _nbAccounts << ";" << std::flush;
// 	std::cout << "total:" << _totalAmount << ";" << std::flush;
// 	std::cout << "deposits:" << _totalNbDeposits << ";" << std::flush;
// 	std::cout << "withdrawals:" << _totalNbWithdrawals << END << std::flush << std::endl;
// }

// /**
//  * @brief Get current time stamp.
//  * 
//  * @link https://stackoverflow.com/questions/27934034/get-current-time-in-mm-dd-yyyy-in-c
//  * @link https://codescracker.com/cpp/cpp-date-time.htm
//  */
// void	Account::_displayTimestamp(void)
// {
// 	std::time_t	time;

// 	time = std::time(NULL);
// 	std::cout << std::setfill('0') << "["
// 		<< std::setw(2) << 1900 + std::localtime(&time)->tm_year
// 		<< std::setw(2) << 1 +  std::localtime(&time)->tm_mon
// 		<< std::setw(2) << std::localtime(&time)->tm_mday << "_"
// 		<< std::setw(2) << std::localtime(&time)->tm_hour
// 		<< std::setw(2) << std::localtime(&time)->tm_min
// 		<< std::setw(2) << std::localtime(&time)->tm_sec
// 		<< "] " << std::flush;
// 	/*
// 	char buffer[16];
// 	time_t start;
// 	time(&start);

// 	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&start));
// 	std::cout << '[' << buffer << ']';
// 	*/
// }

// void	Account::makeDeposit(int deposit)
// {
// 	_displayTimestamp();
// 	getNbDeposits();
// 	std::cout << YELLOW << "index:" << _accountIndex << ";" << std::flush;
// 	std::cout << "p_amount:" << _amount << ";" << std::flush;
// 	std::cout << "deposit:" << deposit << ";" << std::flush;
// 	std::cout << "amount:" << _amount + deposit << ";" << std::flush;
// 	std::cout << "nb_deposit:" << ++_nbDeposits << END << std::flush << std::endl;
// 	_totalAmount += deposit;
// 	_amount += deposit;
// }


// bool	Account::makeWithdrawal(int withdrawal)
// {
// 	_displayTimestamp();
// 	std::cout  << "index:" << _accountIndex << ";" << std::flush;
// 	std::cout << "p_amount:" << _amount << ";" << std::flush;// previous amount
// 	if (withdrawal <= _amount && withdrawal > 0)
// 	{
// 		getNbWithdrawals();
// 		std::cout << "withdrawal:" << withdrawal << ";" << std::flush;
// 		std::cout << "amount:" << _amount - withdrawal << ";" << std::flush;
// 		std::cout << "nb_withdrawals:" << ++_nbWithdrawals << END << std::flush << std::endl;
// 		_totalAmount -= withdrawal;
// 		_amount -= withdrawal;
// 		return (true);// 1
// 	}
// 	std::cout  << "refused" << END << std::flush << std::endl;
// 	return (false);// 0
// }

// int		Account::checkAmount(void) const
// {
// 	std::cout << "checkAmount" << std::flush << std::endl;
// 	return (0);
// }

// void	Account::displayStatus(void) const
// {
// 	_displayTimestamp();// Printing time.
// 	std::cout  << "index:" << _accountIndex << ";" << std::flush;
// 	std::cout << "amount:" << _amount << ";" << std::flush;
// 	std::cout << "deposits:" << _nbDeposits << ";" << std::flush;
// 	std::cout << "withdrawals:" << _nbWithdrawals << END << std::flush << std::endl;
// }