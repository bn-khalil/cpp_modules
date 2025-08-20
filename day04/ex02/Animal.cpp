/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:35:41 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 15:06:00 by kben-tou         ###   ########.fr       */
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
