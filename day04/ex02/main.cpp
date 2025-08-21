/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:06 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 22:38:50 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void a() {
    system("leaks abstract");
}

int main()
{
    atexit(a);
    const Animal *animals[4];

    for (int i = 0; i < 4; i++)
    {
        if ( i < 8 )
            animals[i] = new Cat();
        else 
            animals[i] = new Dog();
    }
    
    animals[1]->getBrain()->setIdea("hi");
    std::cout << animals[1]->getBrain()->getIdeas()[0] << std::endl;
    
    for (int i = 0; i < 4; i++)
        delete animals[i];

    return 0;
}