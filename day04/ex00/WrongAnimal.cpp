/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:10:29 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 16:22:18 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal( std::string type) {
    this->type = type;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) {
    *this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

WrongAnimal::~WrongAnimal() {}

std::string WrongAnimal::getType() const {
    return ( this->type );
}

void WrongAnimal::makeSound() const {
    std::cout << "wrong animal sound" << std::endl;
}
