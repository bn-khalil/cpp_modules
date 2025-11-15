#ifndef BTC_H
#define BTC_H

#include <iostream>
#include <map>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;

        void suprateInputKeyValue(std::string const & line, std::string & key, std::string & value);
        void suprateDataKeyValue(std::string const & line, std::string & key, std::string & value);
        bool dateValidator(std::string date);
        bool ValueValidator(std::string value);
        void exchangeDisplay(std::string key, float value);
        std::string skeepSpaces(std::string ele);

    public:
        BitcoinExchange();
        BitcoinExchange( const BitcoinExchange & other );
        BitcoinExchange & operator = ( const BitcoinExchange & other );
        ~BitcoinExchange();

        bool readAndParseInput(const char * fileName);
        void readAndParseDatabase(std::ifstream & input);
};

#endif