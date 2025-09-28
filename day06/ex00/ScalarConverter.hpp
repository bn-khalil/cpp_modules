
#ifndef SCALCONVERTER_H
#define SCALCONVERTER_H

#include <iostream>

class ScalarConverter {

    private:
        static bool isPseudo(std::string arg);
        static void displayPseudoLiterals(std::string arg);
        static std::string trimSpaces(std::string arg);
        static bool isChar(std::string arg);
        static void printChar(std::string arg);
        static bool isNum(std::string arg);
        static void displayInterger(int num);
        static void displayFloat(float num);
        static void displayDouble(double num);
        static void displayImpossible();
        static bool isFloat(std::string arg);
        static bool isDouble(std::string arg);

        ScalarConverter();
        ScalarConverter( const ScalarConverter &other );
        ScalarConverter& operator= ( const ScalarConverter &diff );
        ~ScalarConverter();
    public:
        static void convert( std::string arg );
};



#endif