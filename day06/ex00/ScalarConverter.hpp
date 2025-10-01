
#ifndef SCALCONVERTER_H
#define SCALCONVERTER_H

#include <iostream>
#include "Utils.hpp"

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter &other );
        ScalarConverter& operator= ( const ScalarConverter &diff );
        ~ScalarConverter();
    public:
        static void convert( std::string arg );
};



#endif