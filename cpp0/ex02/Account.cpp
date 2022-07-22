#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
Account::Account(int initial_deposit)
{
	this->_accountIndex = 0;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 1;
	this->totalNbDeposits += 1;
	this->_totalAmount += initial_deposit;
}

Account::~Account(){}

int Account::getNbAccounts()
{
	std::cout << this->_nbAccounts;
}

int	Account::getTotalAmount(){
	std::cout << this->_totalAmount;
}

int	Account::getNbDeposits(){
	std::cout << this->_totalNbDeposits;
}

int	Account::getNbWithdrawals(){
	std::cout << this->_total;

void	Account::makeDeposit(int deposit){
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposit +=1;
	this->_totalNbDeposits += 1;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount - withdrawal < 0)
		return false;
	this->_amount -= withdrawal;
	this->_totalAmount -=withdrawal;
	this->_nbWithdrawals += 1;
	this->_totalNbWithdrawals += 1;
}

int		Account::checkAmount() const;
{

}
void	Account::displayStatus() const;
//void	Account::displayAccountsInfos( void );
