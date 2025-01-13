#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


int Account::_nbAccounts = 0 ;
int Account::_totalAmount = 0 ;
int Account::_totalNbDeposits = 0 ;
int Account::_totalNbWithdrawals = 0 ;

void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp() ;
	std::cout	<< " accounts:"		<< Account::getNbAccounts()
				<< ";total:"		<< Account::getTotalAmount()
				<< ";deposits:"		<< Account::getNbDeposits()
				<< ";withdrawals:"	<< Account::getNbWithdrawals()
				<< std::endl ;
}

void Account::_displayTimestamp( void ) {
	std::time_t time = std::time(NULL) ;
	std::tm *localTime = std::localtime(&time) ;
	std::cout 	<< "["
				<< std::setfill('0')
				<< std::setw(4) << localTime->tm_year + 1900
				<< std::setw(2) << localTime->tm_mon + 1
				<< std::setw(2) << localTime->tm_mday
				<< "_" 
				<< std::setw(2) << localTime->tm_hour
				<< std::setw(2) << localTime->tm_min
				<< std::setw(2) << localTime->tm_sec
				<< "]" ;
}

Account::Account( int initial_deposit ) : _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = Account::getNbAccounts() ;
	_nbAccounts++ ;
	_totalAmount += initial_deposit ;
	this->_amount = initial_deposit ;
	Account::_displayTimestamp() ;
	std::cout	<< " index:"	<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";created"
				<< std::endl ;
}

Account::Account( void ) {}

Account::~Account( void ) {
	_nbAccounts-- ;
	_totalAmount -= this->_amount ;
	Account::_displayTimestamp() ;
	std::cout	<< " index:"	<< this->_accountIndex
				<< ";amount:"	<< this->_amount
				<< ";closed"
				<< std::endl ;
}

int	Account::getNbAccounts( void ) { return _nbAccounts ;}
int	Account::getTotalAmount( void ) { return _totalAmount ;}
int	Account::getNbDeposits( void ) { return _totalNbDeposits ;}
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals ;}

void Account::makeDeposit( int deposit ) {
	this->_amount += deposit ;
	_totalAmount += deposit ;
	this->_nbDeposits++ ;
	_totalNbDeposits++ ;
	Account::_displayTimestamp() ;
	std::cout	<< " index:"		<< this->_accountIndex
				<< ";p_amount:"		<< this->_amount - deposit
				<< ";deposit:"		<< deposit
				<< ";amount:"		<< this->_amount
				<< ";nb_deposits:"	<< this->_nbDeposits
				<< std::endl ;
}

bool Account::makeWithdrawal( int withdrawal ) {
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal ;
		_totalAmount -= withdrawal ;
		this->_nbWithdrawals++ ;
		_totalNbWithdrawals++ ;
		Account::_displayTimestamp() ;
		std::cout	<< " index:"			<< this->_accountIndex
					<< ";p_amount:"			<< this->_amount + withdrawal
					<< ";withdrawal:"		<< withdrawal
					<< ";amount:"			<< this->_amount
					<< ";nb_withdrawals:"	<< this->_nbWithdrawals
					<< std::endl ;
		return true ;
	}
	else
	{
		Account::_displayTimestamp() ;
		std::cout	<< " index:"			<< this->_accountIndex
					<< ";p_amount:"			<< this->_amount
					<< ";withdrawal:refused"
					<< std::endl ;
		return false ;
	}
}

int Account::checkAmount( void ) const {
	std::cout << "Va niquer ta mere" << std::endl ;
	return 42 ;
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp() ;
	std::cout	<< " index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl ;
}
