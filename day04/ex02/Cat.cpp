/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:18:01 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 22:30:54 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "Cat Constructor Called!" << std::endl;
    this->brain = new Brain();
}

Cat::Cat( const Cat &other ) {
    std::cout << "Cat copy Constructor Called!" << std::endl;
    *this = other;
}

Cat& Cat::operator=( const Cat &other ) {
    if ( this != &other) {
        this->type = other.type;
        this->brain = new Brain( *other.brain );
    }
    return ( *this );
}

Cat::~Cat() {
    std::cout << "Cat Destructor Called!" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << this->type << " Meow" << std::endl;
}

Brain *Cat::getBrain() const {
    return ( this->brain );
}

void Cat::setBrain( Brain *brain ) {
    this->brain = brain;
}