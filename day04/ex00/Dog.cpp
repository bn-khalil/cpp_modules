/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:50:44 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/24 22:03:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout << "Dog Constructor Called!" << std::endl;
}

Dog::Dog( const Dog &other ): Animal("Dog") {
    std::cout << "Dog copy Constructor Called!" << std::endl;
    *this = other;
}

Dog& Dog::operator=( const Dog &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

Dog::~Dog() {
    std::cout << "Dog Destructor Called!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << this->type << " bark" << std::endl;
}