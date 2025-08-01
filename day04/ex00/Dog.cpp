#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {}

Dog::Dog( const Dog &other ) {
    *this = other;
}

Dog& Dog::operator=( const Dog &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Dog::~Dog() {}

void Dog::makeSound() const {
    std::cout << this->type << " bark" << std::endl;
}