#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream database("data.csv");
    if (!database.is_open()) {
        std::string message = "Error: could not open file.";
        throw message; // should be handled in error hading phase
    }
    readAndParseDatabase(database);
    // loading data from database file
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
    *this = other;
}

BitcoinExchange & BitcoinExchange::operator = ( const BitcoinExchange &other ) {
    if (this != &other) 
        this->data = other.data;
    return ( *this );
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::suprateInputKeyValue(std::string const & line, 
    std::string & key, std::string & value) {
    if (line.empty())
        return ;
    int supIndex = line.find(" | ");
    if (supIndex < 0) {
        key = line;
        return ;
    }
    try {
        key = line.substr(0, supIndex);
        value = line.substr(supIndex + 3);
    } catch( std::exception const & e) {}
}

void BitcoinExchange::suprateDataKeyValue(std::string const & line, 
    std::string & key, std::string & value) {
    if (line.empty())
        return ;
    int supIndex = line.find(",");
    if (supIndex < 0) {
        key = line;
        return ;
    }
    try {
        key = line.substr(0, supIndex);
        value = line.substr(supIndex + 1);
    } catch( std::exception const & e) {}
}

bool BitcoinExchange::dateValidator(std::string date) {

    // empty row
    if (date.empty())
        return false;

    // missing or adding

    if ( date.size() != 10)
        return false;

    // check suparator

    if ( date[4] != '-' || date[7] != '-')
        return false;

    // check years months days

    std::string dateArray[3];
    dateArray[0] = date.substr(0, 4);
    dateArray[1] = date.substr(5, 2);
    dateArray[2] = date.substr(8, 2);

    for( size_t i = 0; i < 3; i++) {
        for( size_t j = 0; j < dateArray[i].size(); j++) {
            if (!std::isdigit(dateArray[i][j]))
                return false;
        }
        double time = std::atof(dateArray[i].c_str());
        // waiting for confirmation checking with the current time
        if (i == 1 && ( time > 12 || time <= 0) )
                return false;
        else if (i == 2 && ( time > 30 || time <= 0))
                return false;
    }
    return true;
}

bool BitcoinExchange::ValueValidator(std::string value) {
    float num;

    if (value.empty()) {
        std::cout << "Error: value is empty." << std::endl;
        return false;
    }
    size_t i = 0;
    if (value[i] == '+')
        i++;

    if (value[i] == '.') {
        std::cout << "Error: value is not digit." << std::endl;
        return false;
    }

    if (i == value.size()) {
        std::cout << "Error: value is not digit." << std::endl;
        return false;
    }
    for(; i < value.size(); i++) {
        if (!std::isdigit(value[i]) && value[i] != '.') {
            std::cout << "Error: value is not digit." << std::endl;
            return false;
        }
    }
    num = std::atof(value.c_str());
    if (num < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    } else if (num > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::exchangeDisplay(std::string key, double value) {
    std::map<std::string, float>::iterator item = this->data.find(key);
    if (item == this->data.end()) {
        std::map<std::string, float>::iterator closest;
        std::map<std::string, float>::iterator it = this->data.begin();
        if (key < it->first)
            std::cout << key << " => " << value << " = " << it->second * value << std::endl;
        else {
            while(it != this->data.end()) {
                if (it->first <= key)
                    closest = it;
                else
                    break ;
                it++;
            }
            std::cout << key << " => " << value << " = " << closest->second * value << std::endl;
        }
    }
    else 
        std::cout << key << " => " << value << " = " << item->second * value << std::endl;
}


bool BitcoinExchange::readAndParseInput(const char * fileName) {
    std::string line;
    std::string file(fileName);

    if (file.empty())
        return false;

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
        return false;

    while(std::getline(inputFile, line) && line.empty())
        ;

    if (line != "date | value") {
        std::cout << "Error: bad input => not in the following format: 'data | value'" << "." << std::endl;
        return true;
    }

    while (std::getline(inputFile, line)) {
        std::string key;
        std::string value;
        if (line.empty())
            continue ;        
        this->suprateInputKeyValue(line, key, value);

        if (!this->dateValidator(key)) {
            std::cout << "Error: bad input => " << key << "." << std::endl;
            continue ;
        }
        if (!this->ValueValidator(value))
            continue ;
        double convertedValue = std::atof(value.c_str());
        exchangeDisplay(key, convertedValue);
    }
    return true;
}

void BitcoinExchange::readAndParseDatabase( std::ifstream & database) {
    std::string line;

    while(std::getline(database, line) && line.empty())
        ;
    if (line != "date,exchange_rate") {
        std::cout << "Error: bad input => not in the following format: 'date,exchange_rate'" << "." << std::endl;
        return ;
    }
    while (std::getline(database, line)) {
        std::string key;
        std::string value;
        if (line.empty())
            continue ;
        this->suprateDataKeyValue(line, key, value);
        double convertedValue = std::atof(value.c_str());
        this->data[key] = convertedValue;
    }
    database.close();
}

void BitcoinExchange::displayData() {
    for(std::map<std::string, float >::iterator it = data.begin() 
    ; it != data.end()
    ; it++) {
        std::cout << "key => " << it->first << "value => " << it->second << std::endl;
    }
}
