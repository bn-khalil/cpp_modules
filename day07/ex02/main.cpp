#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
    // valid cases:

    Array<int> store(4);
    std::cout << "size of store = " << store.size() << std::endl;
    
    for(size_t i = 0; i < 4; i++) {
        store[i] = i * 2;
    }

    for(size_t i = 0; i < 4; i++) {
        std::cout << store[i] << std::endl;
    }

    Array<int> hold = store;
    std::cout << "size of hold = " << hold.size() << std::endl;

    for(size_t i = 0; i < 4; i++) {
        std::cout << hold[i] << std::endl;
    }

    Array<int> copy;
    
    std::cout << "size of copy = " << copy.size() << std::endl;

    copy = hold;
    
    for(size_t i = 0; i < 4; i++) {
        std::cout << copy[i] << std::endl;
    }
    
    // incorrect cases: 

    try {
        store[-2121] = 12;
    } catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        store[2121] = 12;
    } catch(std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}