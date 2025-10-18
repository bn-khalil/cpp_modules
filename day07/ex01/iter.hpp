#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t length, F funptr) {
    if (array) {
        for (size_t i = 0; i < length; i++)
            funptr(array[i]);
    }
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