#include "Cat.hpp"


Cat::Cat(): Animal("Cat") {}

Cat::Cat( const Cat &other ) {
    *this = other;
}

Cat& Cat::operator=( const Cat &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Cat::~Cat() {}

void Cat::makeSound() const {
    std::cout << this->type << " purring" << std::endl;
}