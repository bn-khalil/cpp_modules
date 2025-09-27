
#ifndef SCALCONVERTER_H
#define SCALCONVERTER_H

#include <iostream>

class ScalarConverter {

    private:
        static bool isPseudo(std::string str);
        static void displayPseudoLiterals(std::string str);
        static std::string trimSpaces(std::string str);
        static bool isChar(std::string str);
    public:
        ScalarConverter();
        ScalarConverter( const ScalarConverter &other );
        ScalarConverter& operator= ( const ScalarConverter &diff );
        ~ScalarConverter();

        static void convert( std::string str );
};



#endif