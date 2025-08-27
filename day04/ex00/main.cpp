/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:51:36 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 11:09:26 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    cat->makeSound();
    cat->makeSound();
    meta->makeSound();Cat::Cat(): Animal("Cat") {
    std::cout << "Cat Constructor Called!" << std::endl;
    this->brain = new Brain();
}

Cat::Cat( const Cat &other ): Animal("Cat") {
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
    dog->makeSound();
    dog->makeSound();

    const WrongAnimal* beta = new WrongCat();
    beta->makeSound();
    
    delete meta;
    delete cat;
    delete dog;
    delete beta;

    return 0;
}