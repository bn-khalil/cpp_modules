/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:45:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 19:50:09 by kben-tou         ###   ########.fr       */
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
        Brain *brain;
    public:
        Animal();
        Animal( std::string type);
        Animal( const Animal &other );
        Animal &operator=( const Animal &other );
        virtual ~Animal();

        virtual void makeSound() const = 0;
};
#endif