/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:51:44 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 22:37:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog") {
    std::cout << "Dog Constructor called!" << std::endl;
    this->brain = new Brain();
}

Dog::Dog( const Dog &other ) {
    std::cout << "Dog Constructor Called!" << std::endl;
    *this = other;
}

Dog& Dog::operator=( const Dog &other ) {
    if ( this != &other) {
        this->type = other.type;
        this->brain = new Brain( *other.brain );
    }
    return ( *this );
}

Dog::~Dog() {
    std::cout << "Dog Distructor called!" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << this->type << " bark" << std::endl;
}

Brain *Dog::getBrain() const {
    return ( this->brain );
}

void Dog::setBrain( Brain *brain ) {
    this->brain = brain;
}
