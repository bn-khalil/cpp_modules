/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:58:06 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/02 11:35:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>


int main()
{
    const Animal *animals[16];

    for (int i = 0; i < 16; i++)
    {
        if ( i < 8 )
            animals[i] = new Cat();
        else 
            animals[i] = new Dog();
    }
    
    for (int i = 0; i < 16; i++)
        delete animals[i];

    return 0;
}