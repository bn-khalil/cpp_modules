#include "ScalarConverter.hpp"

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

bool ScalarConverter::isPseudo(std::string str) {
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
        return true;
    return false;
}

std::string ScalarConverter::trimSpaces(std::string str) {
    size_t start = 0;
    size_t end = str.length();

    while (start < str.length() && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
        start++;
    while (end > start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
        end--;
    return str.substr(start, end - start);
}

bool ScalarConverter::isChar(std::string str) {
    if (str[i] >= 32 && str[i] < 127)
    return false;
}

void ScalarConverter::displayPseudoLiterals(std::string str) {
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (str == "-inf" || str == "-inff") {
        std::cout << "float: " << "-inf" << std::endl;
        std::cout << "double: " << "-inff" << std::endl;
    } else if (str == "+inf" || str == "+inff") {
        std::cout << "float: " << "+inf" << std::endl;
        std::cout << "double: " << "+inff" << std::endl;
    }
    else {
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
}



void ScalarConverter::convert( std::string str ) {

    if (isPseudo(str)) {
        displayPseudoLiterals(str);
        return ;
    }
    std::string cmd = trimSpaces(str);
    if (cmd.length == 1 && isChar())

}
