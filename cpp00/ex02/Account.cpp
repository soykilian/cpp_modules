#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);

	std::tm now = *localtime(&t);
	std::cout << "[" << now.tm_year + 1900 <<  std::setfill('0') << std::setw(2) << now.tm_mon + 1 << std::setw(2) << now.tm_mday << "_" << std::setw(2) << now.tm_hour << std::setw(2) << now.tm_min << std::setw(2) << now.tm_sec  << "] ";
}
Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"<< this->_amount << ";created\n";
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"<< this->_amount << ";closed\n";
}

int Account::getNbAccounts()
{
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount(){
	return(Account::_totalAmount);
}

int	Account::getNbDeposits(){
	 return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(){
	 return(Account::_totalNbWithdrawals);
}

void	Account::makeDeposit(int deposit){
	this->_nbDeposits +=1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"<< this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" <<  this->_nbDeposits << "\n";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:"<< this->_amount << ";withdrawal:refused\n";
		return false;
	}
	this->_nbWithdrawals += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"<< this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" <<  this->_nbWithdrawals << "\n";
	this->_amount -= withdrawal;
	Account::_totalAmount -=withdrawal;
	Account::_totalNbWithdrawals += 1;
	return true;
}

int		Account::checkAmount() const
{
	return(this->_amount);
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"<< this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

