#include "ScalarConverter.hpp"
#include <string>
#include <iomanip>


ScalarConverter::ScalarConverter( void ) {
    std::cout << "ScalarConverter Default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& diff ) {
    std::cout << "Copy ScalarConverter constructor called!" << std::endl;
    (void)diff;
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter &diff ) {
    std::cout << "Copy ScalarConverter assiment operator called!" << std::endl;
    (void)diff;
    return ( *this );
}

ScalarConverter::~ScalarConverter( void ) {
    std::cout << "ScalarConverter Destructor called!" << std::endl;
}

bool ScalarConverter::isPseudo(std::string arg) {
    if (arg == "nan" || arg == "nanf" 
        || arg == "+inf" || arg == "-inf" 
        || arg == "+inff" || arg == "-inff")
        return true;
    return false;
}

std::string ScalarConverter::trimSpaces(std::string arg) {
    size_t start = 0;
    size_t end = arg.length();

    while (start < arg.length() && (arg[start] == ' ' || arg[start] == '\t' || arg[start] == '\n'))
        start++;
    while (end > start && (arg[end] == ' ' || arg[end] == '\t' || arg[end] == '\n'))
        end--;
    return arg.substr(start, end - start);
}

bool ScalarConverter::isChar(std::string arg) {
    if (std::isprint(arg[0]) && !std::isdigit(arg[0]))
        return true;
    return false;
}

bool ScalarConverter::isNum(std::string arg) {
    size_t i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    if (arg.length() == i)
        return false;
    while(i < arg.length() && std::isdigit(arg[i]))
        i++;
    if (arg.length() == i)
        return true;
    return false;
}

void ScalarConverter::displayPseudoLiterals(std::string arg) {
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (arg == "-inf" || arg == "-inff") {
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
    } else if (arg == "+inf" || arg == "+inff") {
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
    }
    else {
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
}

void ScalarConverter::printChar(std::string arg) {
    if (isChar(arg))
        std::cout << "char: '" << arg[0] << "'"<< std::endl;
    else
        std::cout << "char: impossible"<< std::endl;
    std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(arg[0]) << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(arg[0]) << std::endl;
}

void ScalarConverter::displayInterger(int num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: impossible"<< std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::displayFloat(float num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: impossible"<< std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << num << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::displayDouble(double num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: impossible"<< std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
    std::cout << "double: " << num << std::endl;
}

void ScalarConverter::displayImpossible() {
    std::cout << "char: impossible"<< std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::isFloat(std::string arg) {
    size_t i = 0;
    bool point = false;

    if (arg.back() != 'f')
        return false;
    if (arg[0] == '-' || arg[0] == '+')
        i++;
    
    if ((arg.length() - 1) == i)
        return false;
    while(i < arg.length() - 1) {
        if (arg[i] == '.' && point == false) {
            point = true;
            i++;
            continue;
        }
        if (!std::isdigit(arg[i]))
            return false;
        i++;
    }
    if (!point)
        return false;
    return true;
}

bool ScalarConverter::isDouble(std::string arg) {
    size_t i = 0;
    bool point = false;

    if (arg[0] == '-' || arg[0] == '+')
        i++;
    if (arg.length() == i)
        return false;
    while(i < arg.length() - 1) {
        if (arg[i] == '.' && point == false) {
            point = true;
            i++;
            continue;
        }
        if (!std::isdigit(arg[i]))
            return false;
        i++;
    }
    if (!point)
        return false;
    return true;
}

void ScalarConverter::convert( std::string arg ) {

    if (isPseudo(arg)) {
        displayPseudoLiterals(arg);
        return ;
    }
    // std::arging arg = trimSpaces(arg);

    if (isNum(arg))
        displayInterger(std::stoi(arg));
    else if (arg.size() <= 1)
        printChar(arg);
    else if (isFloat(arg))
        displayFloat(std::stof(arg));
    else if (isDouble(arg))
        displayDouble(std::stod(arg));
    else
        displayImpossible();
}
