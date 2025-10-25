#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    std::ifstream input(argv[1]);
    std::ifstream database("data.csv");
    if (!input.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        database.close();
        return 1;
    }
    if (!database.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        input.close();
        return 1;
    }

    BitcoinExchange btc;

    std::string line;
    bool skeeper = false;
    while (std::getline(input, line)) {
        std::string key;
        std::string value;
        if (skeeper){
            btc.suprateKeyValue(line, key, value);
            btc.push(key, value);
        }
        skeeper = true;
    }

    btc.display();

    input.close();
    database.close();
    return 0;
}
