#include <iostream>
#include <fstream>

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

    BitcoinExchange btc();

    std::string line;
    while (std::getline(input, line)) {
        std::cout << line << std::endl;
    }

    input.close();
    database.close();
    return 0;
}
