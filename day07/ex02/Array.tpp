#include "Array.hpp"

template <typename T>
Array<T>::Array(): len(0) {
    std::cout << "Array Default constructor called!" << std::endl;
    array = new T [0];
}

template <typename T>
Array<T>::Array( unsigned int n ): len(n) {
    std::cout << "params Array constructor called!" << std::endl;
    array = new T [n];
}

template <typename T>
Array<T>::Array( const Array& diff ): len(diff.size()) {
    std::cout << "Copy Array constructor called!" << std::endl;
    array = new T[diff.size()];

    for (unsigned int i = 0; i < diff.size(); i++)
        this->array[i] = diff[i];
}

template <typename T>
Array<T>& Array<T>::operator= ( const Array &diff ) {
    std::cout << "Copy Array assiment operator called!" << std::endl;
    (void)diff;
    return ( *this );
}

template <typename T>
unsigned int Array<T>::size() const {
    return len;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array Destructor called!" << std::endl;
}

template <typename T>
T& Array<T>::operator[] (int i) const{
    if (i < 0 || i >= static_cast<int>(size()))
        throw std::out_of_range("index out of bounds!");
    return array[i];
}
