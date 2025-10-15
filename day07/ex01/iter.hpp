#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T array[], size_t length, void (*funptr)(T &));

#endif