#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account( void ){
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"amount:"<<this->_amount<<";"\
    <<"closed"<<std::endl;
}
Account::Account(int initial_deposit){
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

void Account::displayAccountsInfos( void ) {
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    std::cout<< "index:"<< this->_accountIndex<<";" \
    <<"p_amount:"<<this->_amount<<";" \
    <<"deposit:"<<deposit<<";";
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout <<"amount:"<<this->_amount<<";"\
    << "nb_deposits:"<< this->_nbDeposits<<";"\
    <<std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
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
    <<"withdrawals:" << this->_nbWithdrawals<<";"\
    <<std::endl;
    return (true);
}

int		Account::checkAmount( void ) const {
    return (this->_amount);
}
void	Account::displayStatus( void ) const{
    std::cout<< "index:"<< this->_accountIndex<<";"\
    <<"amount:"<<this->_amount<<";"\
    << "deposits:"<< this->_nbDeposits<<";"\
    <<"withdrawals:" << this->_nbWithdrawals<<";"\
    <<std::endl;
}
void	Account::_displayTimestamp( void ) {

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

