#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    std::ifstream database("data.csv");

    if (!database.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        input.close();
        return 1;
    }

    BitcoinExchange btc;

    btc.readAndParseInput(input);
    // btc.readAndParseDatabase(input);

    btc.display();

    input.close();
    database.close();
    return 0;
}
