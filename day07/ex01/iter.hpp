#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T array[], const size_t length, void (*funptr)(T &)) {
    for (size_t i = 0; i < length; i++)
        funptr(array[i]);
}

template <typename T>
void display(T & f){
    std::cout << f << std::endl;
}

template <typename T>
void increament(T & i){
    i++;
}

#endif