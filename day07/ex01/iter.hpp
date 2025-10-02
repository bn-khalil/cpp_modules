#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>

void iter(T array[], size_t length, void (*funptr)(T &)) {
    for (size_t i = 0; i < length; i++)
        funptr(array[i]);
}

#endif