/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:18:01 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 18:42:35 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
    std::cout << "Cat Constructor called!" << std::endl;
    this->brain = new Brain();
}

Cat::Cat( const Cat &other ) {
    *this = other;
}

Cat& Cat::operator=( const Cat &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Cat::~Cat() {
    std::cout << "Cat Distructor called!" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << this->type << " Meow" << std::endl;
}