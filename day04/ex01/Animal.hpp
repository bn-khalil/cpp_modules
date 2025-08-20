/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:00:36 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 12:46:09 by kben-tou         ###   ########.fr       */
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

        std::string getType() const;
        virtual void makeSound() const;
        virtual Brain *getBrain() const;
};
#endif