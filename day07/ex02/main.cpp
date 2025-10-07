#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

template <typename T>
const char* Array<T>::ArrayException:: what() const throw(){
    return ( "index out of bounds exception!" );
}

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
    for (unsigned int i = 0; i < diff.size(); i++) {
        this->array[i] = diff[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator= ( const Array &diff ) {
    std::cout << "Copy Array assiment operator called!" << std::endl;
    if (this != &diff) {
        delete[] this->array;
        this->array = new T[diff.size()];
        for (unsigned int i = 0; i < diff.size(); i++)
            this->array[i] = diff[i];
        this->len = diff.len;
    }
    return ( *this );
}

template <typename T>
unsigned int Array<T>::size() const {
    return len;
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array Destructor called!" << std::endl;
    delete []array;
}

template <typename T>
T& Array<T>::operator[] (int i) const {
    if (i < 0 || i >= static_cast<int>(size()))
        throw Array<T>::ArrayException();
    return array[i];
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE
    {
        Array<int> tmp = numbers;

        Array<int> test(tmp);
        test = numbers;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}