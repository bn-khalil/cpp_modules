#ifndef BTC_H
#define BTC_H

#include <iostream>
#include <list>

class BitcoinExchange
{
    private:
        std::list<std::pair<std::string, long> > data;
        std::list<std::pair<std::string, long> > actions;

    public:
        BitcoinExchange();
        BitcoinExchange( const BitcoinExchange & other );
        BitcoinExchange & operator = ( const BitcoinExchange & other );
        ~BitcoinExchange();

        void push(std::string key, std::string value) {
            double convertedValue = std::atof(value.c_str());
            if (convertedValue < 0 || convertedValue >= INT_MAX) {
                std::cout << "throw a specific exception for int check!" << std::endl;
                return ;
            }
            this->actions.push_back(std::make_pair(key, convertedValue));
        }

        void suprateKeyValue(std::string const & line, std::string & key, std::string & value) {
            if (line.empty())
                return ;
            int supIndex = line.find("|");
            if (supIndex < 0) {
                key = line;
                return ;
            }
            key = line.substr(0, supIndex);
            value = line.substr(supIndex + 1, line.size() - 1);
        }

        void display() {
            for(std::list<std::pair<std::string, long> >::iterator it = actions.begin() ; it != actions.end(); it++) {
                std::cout << "key => " << it->first << "value => " << it->second << std::endl;
            }
        }
};

#endif