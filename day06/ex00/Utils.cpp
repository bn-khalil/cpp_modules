#include "Utils.hpp"

bool isPseudo(std::string arg) {
    if (arg == "nan" || arg == "nanf" 
        || arg == "+inf" || arg == "-inf" 
        || arg == "+inff" || arg == "-inff")
        return true;
    return false;
}

void displayPseudoLiterals(std::string arg) {
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

void printChar(std::string arg) {
    if (isChar(arg))
        std::cout << "char: '" << arg[0] << "'"<< std::endl;
    else
        std::cout << "char: Non displayable"<< std::endl;
    std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(arg[0]) << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(arg[0]) << std::endl;
}

void displayInterger(int num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: Non displayable"<< std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void displayFloat(float num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: Non displayable"<< std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << num << "f"<< std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void displayDouble(double num) {
    if (num >= 32 && num <= 126)
        std::cout << "char: '" << static_cast<char>(num) << "'"<< std::endl;
    else
        std::cout << "char: Non displayable"<< std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num) << "f"<< std::endl;
    std::cout << "double: " << num << std::endl;
}

void displayImpossible() {
        std::cerr << "Error: The enterd input is wrong!" << std::endl;
}

bool isChar(std::string arg) {
    if (std::isprint(arg[0]) && !std::isdigit(arg[0]))
        return true;
    return false;
}

bool isNum(std::string arg) {
    size_t i = 0;
    if (arg.front() == '-' || arg.front() == '+')
        i++;
    if (arg.length() == i)
        return false;
    while(i < arg.length() && std::isdigit(arg[i]))
        i++;
    if (arg.length() == i)
        return true;
    return false;
}

bool isFloat(std::string arg) {
    size_t i = 0;
    bool point = false;

    if (arg.back() != 'f')
        return false;
    if (arg.front() == '-' || arg.front() == '+')
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

bool isDouble(std::string arg) {
    size_t i = 0;
    bool point = false;

    if (arg.front() == '-' || arg.front() == '+')
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
