#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange Default constructor called!" << std::endl;
    std::ifstream database("data.csv");
    if (!database.is_open()) {
        std::string message = "Error: could not open file.";
        throw message; // should be handled in error hading phase
    }
    readAndParseDatabase(database);
    // loading data from database file
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) {
    std::cout << "Copy BitcoinExchange constructor called!" << std::endl;
    *this = other;
}

BitcoinExchange & BitcoinExchange::operator = ( const BitcoinExchange &other ) {
    std::cout << "Copy BitcoinExchange assinement operator called!" << std::endl;
    (void) other;
    return ( *this );
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange Destructor called!" << std::endl;
}

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

void BitcoinExchange::push(std::string key, std::string value) {

    double convertedValue = std::atof(value.c_str());
    if (convertedValue < 0 || convertedValue > 1000) {
        std::cout << "throw a specific exception for int check!" << std::endl;
        return ;
    }
    this->actions.push_back(std::make_pair(key, convertedValue));
}

void BitcoinExchange::dateValidator(std::string date) {

    // empty row
    if (date.empty()) {
        std::cout << "throw date in empty!";
        throw std::exception();
    }

    // missing or adding

    if ( date.size() != 10) {
        std::cout << "throw date should be in forma YYYY-MM-DD !";
        throw std::exception();
    }

    // check suparator

    if ( date[4] != '-' || date[7] != '-') {
        std::cout << "throw date should be in forma YYYY-MM-DD !";
        throw std::exception();
    }

    // check years months days

    std::string dateArray[3];
    dateArray[0] = date.substr(0, 4);
    dateArray[1] = date.substr(5, 2);
    dateArray[2] = date.substr(8, 2);

    for( size_t i = 0; i < 3; i++) {
        for( size_t j = 0; j < dateArray[i].size(); j++) {
            if (!std::isdigit(dateArray[i][j]))
                throw std::exception();
        }
        double time = std::atof(dateArray[i].c_str());
        
        // waiting for confirmation checking with the current time
        if (i == 1 && ( time > 12 || time < 0) )
            throw std::exception();
        else if (i == 2 && ( time > 30 || time < 0))
            throw std::exception();
    }
}

void BitcoinExchange::readAndParseInput(const char * fileName) {
    std::string line;
    bool skeeper = false;

    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::string message = "Error: could not open file.";
        throw message; // should be handled in error hading phase
    }

    while (std::getline(inputFile, line)) {
        std::string key;
        std::string value;
        if (!skeeper) {
            if (line == static_cast<std::string>("date | value")) {
                skeeper = true;
                continue;
            } else 
                throw std::exception(); // throw the correct exception
        }
        if (skeeper){
            this->suprateInputKeyValue(line, key, value);
            this->dateValidator(key);
            this->push(key, value);
        }
    }
}

void BitcoinExchange::readAndParseDatabase( std::ifstream & database) {
    std::string line;
    bool skeeper = false;

    while (std::getline(database, line)) {
        std::string key;
        std::string value;
        if (skeeper) {
            // std::cout << line << std::endl;
            this->suprateDataKeyValue(line, key, value);
            double convertedValue = std::atof(value.c_str());
            this->data.push_back(std::make_pair(key, convertedValue));
        }
        skeeper = true;
    }
}

void BitcoinExchange::display() {
    for(std::list<std::pair<std::string, double> >::iterator it = actions.begin() 
    ; it != actions.end()
    ; it++) {
        std::cout << "key => " << it->first << "value => " << it->second << std::endl;
    }
}

void BitcoinExchange::displayData() {
    for(std::list<std::pair<std::string, double> >::iterator it = data.begin() 
    ; it != data.end()
    ; it++) {
        std::cout << "key => " << it->first << "value => " << it->second << std::endl;
    }
}

const char * BitcoinExchange::FileNotFoundException::what() const throw() {
    return "Error: could not open file.";
}

const char * BitcoinExchange::InvalidDateException::what() const throw() {
    return "Error: bad input => ";
}

const char * BitcoinExchange::InvalidValueException::what() const throw() {
    return "Error: value not valid.";
}

const char * BitcoinExchange::InvalidFormatException::what() const throw() {
    return "Error: Format not valid 'date | value'.";
}

const char * BitcoinExchange::NegativeNumberException::what() const throw() {
    return "Error: not a positive number.";
}