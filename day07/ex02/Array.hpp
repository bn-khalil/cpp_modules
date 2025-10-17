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
        Array(): array(new T [0]), len(0) {
            std::cout << "Array Default constructor called!" << std::endl;
        }

        Array( unsigned int n ):array(new T [n]), len(n) {
            std::cout << "Array params constructor called!" << std::endl;
        }

        Array( const Array &other ): len(other.size()) {
            std::cout << "Copy Array constructor called!" << std::endl;
            array = new T[other.size()];
            for (unsigned int i = 0; i < other.size(); i++) {
                this->array[i] = other[i];
            }
        }

        Array &operator = ( const Array &other ){
            std::cout << "Copy Array assiment operator called!" << std::endl;
            if (this != &other) {
                delete[] this->array;
                this->array = new T[other.size()];
                for (unsigned int i = 0; i < other.size(); i++)
                    this->array[i] = other[i];
                this->len = other.len;
            }
            return ( *this );
        }

        ~Array(){
            std::cout << "Array Destructor called!" << std::endl;
            delete []array;
        };

        unsigned int size() const {
            return len;
        }

        T& operator[] (unsigned int i) {
            if (i < 0 || i >= size())
                throw std::exception(); 
            return array[i];
        }

        const T& operator[] (unsigned int i) const {
            if (i < 0 || i >= this->size())
                throw std::exception(); 
            return this->array[i];
        }
};


#endif