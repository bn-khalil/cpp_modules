#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
    private:
        T array[];
    public:
        Array();
        Array( unsigned int n );
        Array( const Array &other );
        Array &operator=( const Array &other );
        ~Array();

        size_t size() const;
};


#endif