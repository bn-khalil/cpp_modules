#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
    _displayTimestamp();
    this->_amount = initial_deposit;
    this->_accountIndex = _nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"amount"<<this->_amount<<";"\
    <<"created"<<std::endl;
}

Account::~Account( void ){
    _displayTimestamp();
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"amount:"<<this->_amount<<";"\
    <<"closed"<<std::endl;
}

void	Account::_displayTimestamp( void ) {
    std::time_t time = std::time(nullptr);
    std::tm *n = std::localtime(&time);
    std::cout << "["
              << std::setfill('0') << std::setw(4) << n->tm_year + 1900
              << std::setw(2) << n->tm_mon + 1
              << std::setw(2) << n->tm_mday << "_"
              << std::setw(2) << n->tm_hour
              << std::setw(2) << n->tm_min
              << std::setw(2) << n->tm_sec
              << "] ";
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    std::cout<< "index:"<< this->_accountIndex<<";" \
    <<"p_amount:"<<this->_amount<<";" \
    <<"deposit:"<<deposit<<";";
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout <<"amount:"<<this->_amount<<";"\
    << "nb_deposits:"<< this->_nbDeposits <<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"p_amount:"<<this->_amount<<";";
    if (withdrawal <= 0 || withdrawal > this->_amount) {
        std::cout<<"withdrawal:refused"<<std::endl;
        return false;
    } 
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout<< "withdrawal:"<< withdrawal<<";"\
    << "amount:"<< this->_amount<<";"\
    <<"withdrawals:" << this->_nbWithdrawals <<std::endl;
    return (true);
}

int		Account::checkAmount( void ) const {
    return (this->_amount);
}

void	Account::displayStatus( void ) const{
    _displayTimestamp();
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"amount:"<<this->_amount<<";"\
    << "deposits:"<< this->_nbDeposits<<";"\
    <<"withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts( void ) {
    return (_nbAccounts);
}
int Account::getTotalAmount( void ) {
    return (_totalAmount);
}
int Account::getNbDeposits( void ) {
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals( void ) {
    return (_totalNbWithdrawals);
}

