/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:18:38 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 16:20:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat") {}

WrongCat::WrongCat( const WrongCat &other ) {
    *this = other;
}

WrongCat& WrongCat::operator=( const WrongCat &other ) {
    if ( this != &other) {
        this->type = other.type;
    }
    return ( *this );
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const {
    std::cout << this->type << " Meow" << std::endl;
}