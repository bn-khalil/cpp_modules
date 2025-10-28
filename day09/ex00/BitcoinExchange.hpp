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

        class FileNotFoundException : public std::exception{
            const char * what() const throw();
        };

        class InvalidDateException : public std::exception{
            const char * what() const throw();
        };

        class InvalidValueException : public std::exception{
            const char * what() const throw();
        };

        class InvalidFormatException : public std::exception{
            const char * what() const throw();
        };

        class NegativeNumberException : public std::exception{
            const char * what() const throw();
        };
};

#endif