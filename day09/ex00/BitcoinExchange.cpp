#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::ifstream database("data.csv");
    if (!database.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }

    readAndParseDatabase(database);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & other ) {
    this->data = other.data;
}

BitcoinExchange & BitcoinExchange::operator = ( const BitcoinExchange &other ) {
    if (this != &other) 
        this->data = other.data;
    return ( *this );
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::suprateInputKeyValue(std::string const & line, 
    std::string & key, std::string & value) {
    int supIndex = line.find("|");
    if (supIndex < 0) {
        key = line;
        return ;
    }
    key = line.substr(0, supIndex);
    value = line.substr(supIndex + 1);
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
    key = line.substr(0, supIndex);
    value = line.substr(supIndex + 1);
}

bool BitcoinExchange::dateValidator(std::string date) {

    if (date.empty())
        return false;

    if ( date.size() != 10)
        return false;

    if ( date[4] != '-' || date[7] != '-')
        return false;

    std::string dateArray[3];
    int daysPerMonth[13] = {1337,31,28,31,30,31,30,31,31,30,31,30,31};

    dateArray[0] = date.substr(0, 4);
    dateArray[1] = date.substr(5, 2);
    dateArray[2] = date.substr(8, 2);

    for( size_t i = 0; i < 3; i++) {
        for( size_t j = 0; j < dateArray[i].size(); j++) {
            if (!std::isdigit(dateArray[i][j]))
                return false;
        }
        long time = std::atol(dateArray[i].c_str());
        if (i == 0) {
            if (time % 400 == 0 || (time % 4 == 0 && time % 100 != 0))
                daysPerMonth[2] = 29;
        }
        if  (i == 0 && time < 2009)
                return false;
        else if (i == 1 && ( time > 12 || time <= 0) )
                return false;
        else if (i == 2) {
            long mo = std::atol(dateArray[1].c_str());
            if ( time > daysPerMonth[mo] || time <= 0)
                return false;
        }
    }
    return true;
}


bool BitcoinExchange::ValueValidator(std::string value) {
    float num;
    int counter = 0;

    if (value.empty()) {
        std::cerr << "Error: value is empty." << std::endl;
        return false;
    }
    size_t i = 0;
    
    if (value[i] == '-'){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value[i] == '+') {
        i++;
        if (value[i] != '\0' && value[i + 1] == '\0' && !isdigit(value[i])) {
            std::cerr << "Error: value not a number." << std::endl;
            return false;
        }
    }

    if (i == value.size()) {
        std::cerr << "Error: value not a number." << std::endl;
        return false;
    }
    for(; i < value.size(); i++) {
        if (!std::isdigit(value[i]) && value[i] != '.') {
            std::cerr << "Error: value not a number." << std::endl;
            return false;
        }
        if (value[i] == '.')
            counter++;
    }
    if (counter > 1) {
        std::cerr << "Error: value not a number." << std::endl;
        return false;
    }

    if (value.size() == 1 && counter == 1 && value[0] == '.') {
        std::cerr << "Error: value not a number." << std::endl;
        return false;
    }
    num = std::atof(value.c_str());
    if (num < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    } else if (num > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::exchangeDisplay(std::string key, float value) {
    std::map<std::string, float>::iterator item = this->data.lower_bound(key);

    if (data.end() == item || item->first != key) {
        if (item == data.begin()) {
            std::cerr << "Error: invalid date ." << std::endl;
            return ;
        }
        --item;
    }
    std::cout << key << " => " << value << " = " << item->second * value << std::endl;
}

std::string BitcoinExchange::skeepSpaces(std::string ele) {
    size_t start = 0;
    size_t end = 0;
    start = ele.find_first_not_of("\n\r \t");
    end = ele.find_last_not_of("\n\r \t");
    if (start >= ele.size() || end < start)
            return "";
    size_t length = end - start + 1;
    return ele.substr(start, length);
}

bool BitcoinExchange::readAndParseInput(const char * fileName) {
    std::string line;
    std::string file(fileName);

    if (this->data.empty())
        return true;

    if (file.empty())
        return false;

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open())
        return false;

    while(std::getline(inputFile, line) && line.empty())
        ;
    if (line.empty())
        return true;
    line = skeepSpaces(line);

    if (line != "date | value") {
        std::cerr << "Error: bad input => not in the following format: 'date | value'" << "." << std::endl;
        return true;
    }

    while (std::getline(inputFile, line)) {
        std::string key;
        std::string value;
        if (line.empty())
            continue ;
        line = skeepSpaces(line);
        this->suprateInputKeyValue(line, key, value);
        if (!key.empty())
            key = skeepSpaces(key);
        if (!value.empty())
            value = skeepSpaces(value);
        if (!this->dateValidator(key)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (!this->ValueValidator(value))
            continue ;
        float convertedValue = std::atof(value.c_str());
        exchangeDisplay(key, convertedValue);
    }
    return true;
}

void BitcoinExchange::readAndParseDatabase( std::ifstream & database) {
    std::string line;

    while(std::getline(database, line) && line.empty())
        ;
    if (line.empty())
        return ;
    line = skeepSpaces(line);
    if (line != "date,exchange_rate") {
        std::cerr << "Error: bad input => not in the following format: 'date,exchange_rate'." << std::endl;
        return ;
    }
    while (std::getline(database, line)) {
        std::string key;
        std::string value;
        if (line.empty())
            continue ;
        line = skeepSpaces(line);
        this->suprateDataKeyValue(line, key, value);
        if (!key.empty())
            key = skeepSpaces(key);
        if (!value.empty())
            value = skeepSpaces(value);
        float convertedValue = std::atof(value.c_str());
        this->data[key] = convertedValue;
    }
}
