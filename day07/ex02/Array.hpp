#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int len;

    public:
        Array(): arr(NULL), len(0) {
            std::cout << "Array Default constructor called!" << std::endl;
        }

        Array( unsigned int n ):arr(new T [n]()), len(n) {
            std::cout << "Array params constructor called!" << std::endl;
        }

        Array( const Array &other ): len(other.len) {
            std::cout << "Copy Array constructor called!" << std::endl;
            this->arr = new T[other.len];
            for (unsigned int i = 0; i < other.len; i++) {
                this->arr[i] = other[i];
            }
        }

        Array &operator = ( const Array &other ){
            std::cout << "Copy Array assiment operator called!" << std::endl;
            if (this != &other) {
                delete[] this->arr;
                this->arr = new T[other.len];
                for (unsigned int i = 0; i < other.len; i++)
                    this->arr[i] = other[i];
                this->len = other.len;
            }
            return ( *this );
        }

        ~Array(){
            std::cout << "Array Destructor called!" << std::endl;
            delete []arr;
        };

        unsigned int size() const {
            return len;
        }

        T& operator[] (unsigned int i) {
            if (i >= this->size())
                throw std::exception(); 
            return arr[i];
        }

        const T& operator[] (unsigned int i) const {
            if (i >= this->size())
                throw std::exception(); 
            return this->arr[i];
        }
};


#endif