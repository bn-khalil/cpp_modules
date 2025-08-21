/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:23 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 21:22:16 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal Constructor Called!" << std::endl;
}

Animal::Animal( std::string type ) {
    std::cout << "Animal parameterized Constructor Called!" << std::endl;
    this->type = type;
}

Animal::Animal( const Animal &other ) {
    std::cout << "Animal copy Constructor Called!" << std::endl;
    *this = other;
}

Animal& Animal::operator=( const Animal &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Animal::~Animal() {
    std::cout << "Animal Destructor Called!" << std::endl;
}

std::string Animal::getType() const {
    return ( this->type );
}

void Animal::makeSound() const {
    std::cout << "Animal make sound!" << std::endl;
}
