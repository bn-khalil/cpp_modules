#ifndef BTC_H
#define BTC_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <fstream>
#include <string>
#include <climits>

class BitcoinExchange
{
    private:
        std::list<std::pair<std::string, double> > data;
        std::list<std::pair<std::string, double> > actions;
        std::ifstream dataBase;
        std::ifstream userInput;

        void suprateInputKeyValue(std::string const & line, std::string & key, std::string & value);
        void suprateDataKeyValue(std::string const & line, std::string & key, std::string & value);
        void push(std::string key, std::string value);
        void dateValidator(std::string date);

    public:
        BitcoinExchange();
        BitcoinExchange( const BitcoinExchange & other );
        BitcoinExchange & operator = ( const BitcoinExchange & other );
        ~BitcoinExchange();

        void readAndParseInput(const char * fileName);
        void readAndParseDatabase(std::ifstream & input);
        void display();
        void displayData();
};

#endif