
#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include "Data.hpp"

class Serializer {

    private:
        Serializer();
        Serializer( const Serializer &other );
        Serializer& operator= ( const Serializer &diff );
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif