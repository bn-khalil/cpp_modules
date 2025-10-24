#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange Default constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
    std::cout << "Copy BitcoinExchange constructor called!" << std::endl;
    *this = other;
}

BitcoinExchange & BitcoinExchange::operator = ( const BitcoinExchange &other ) {
    std::cout << "Copy BitcoinExchange assinement operator called!" << std::endl;
    (void) other;
    return ( *this );
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange Destructor called!" << std::endl;
}