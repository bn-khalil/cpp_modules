/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:45:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 14:56:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        Animal( std::string type);
        Animal( const Animal &other );
        Animal &operator=( const Animal &other );
        virtual ~Animal();

        virtual void makeSound() const = 0;
        virtual Brain *getBrain() const = 0;
};
#endif