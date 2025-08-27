/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:18:38 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 11:21:19 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
    std::cout << "WrongCat Constructor Called!" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other ): WrongAnimal("WrongCat") {
    std::cout << "WrongCat copy Constructor Called!" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=( const WrongCat &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor Called!" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << this->type << " Wrong Meow" << std::endl;
}