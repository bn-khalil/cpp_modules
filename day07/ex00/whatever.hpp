#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <class T>

void swap(T & param1, T & param2) {
    T tmp = param1;
    param1 = param2;
    param2 = tmp;
}

template <class U>

U min(U & param1, U & param2) {
    return param1 < param2 ? param1 : param2;
}

template <class V>

V max(V & param1, V & param2) {
    return param1 > param2 ? param1 : param2;
}

#endif