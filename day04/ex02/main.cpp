/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:06 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 15:05:48 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void a() {
    system("leaks word_on_fire");
}

int main()
{
    atexit(a);
    const Animal *animals[16];

    for (int i = 0; i < 16; i++)
    {
        if ( i < 8 )
            animals[i] = new Cat();
        else 
            animals[i] = new Dog();
    }
    animals[1]->getBrain()->setIdea("hi");
    std::cout << animals[1]->getBrain()->getIdeas()[0] << std::endl;
    for (int i = 0; i < 16; i++)
        delete animals[i];

    return 0;
}