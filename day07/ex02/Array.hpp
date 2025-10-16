#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int len;

    public:
        Array();
        Array( unsigned int n );
        Array( const Array &other );
        Array &operator = ( const Array &other );
        ~Array();

        unsigned int size() const;
        T& operator[] (int i) const;

        class ArrayException: public std::exception {
            const char* what() const throw(); 
        };
};


#endif