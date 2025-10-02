#include "Array.hpp"

Array::Array() {
    std::cout << "Array Default constructor called!" << std::endl;
    this.array = new T [0];
}

Array::Array( unsigned int n ) {
    std::cout << "Copy Array constructor called!" << std::endl;
    this.array = new T [n];
}

Array::Array( const Array& diff ) {
    std::cout << "Copy Array constructor called!" << std::endl;
    if (*this != diff) {
        for (size_t i = 0; i < this->size() && i < diff.size(); i++)
            this->array[i] = diff
    }
}

Array& Array::operator= ( const Array &diff ) {
    std::cout << "Copy Array assiment operator called!" << std::endl;
    (void)diff;
    return ( *this );
}

Array::~Array() {
    std::cout << "Array Destructor called!" << std::endl;
}