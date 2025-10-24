#ifndef BTC_H
#define BTC_H

#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::pair<std::string, double>> data;
        std::map<std::pair<std::string, double>> actions;

    public:
        BitcoinExchange();
        BitcoinExchange( const BitcoinExchange & other );
        BitcoinExchange & operator = ( const BitcoinExchange & other );
        ~BitcoinExchange();

        

};

#endif