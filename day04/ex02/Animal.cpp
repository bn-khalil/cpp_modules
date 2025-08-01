#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal Constructor called!" << std::endl;
    // must add messages for constructors
}

Animal::Animal( std::string type) {
    this->type = type;
}

Animal::Animal( const Animal &other ) {
    *this = other;
}

Animal& Animal::operator=( const Animal &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Animal::~Animal() {
    std::cout << "Animal Distructor called!" << std::endl;
}


