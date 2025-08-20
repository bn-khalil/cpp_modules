/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:10:29 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 10:21:40 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Constructor Called!" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type) {
    std::cout << "WrongAnimal Parametrized Constructor Called!" << std::endl;
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

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor Called!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return ( this->type );
}

void WrongAnimal::makeSound() const {
    std::cout << "wrong animal sound" << std::endl;
}
