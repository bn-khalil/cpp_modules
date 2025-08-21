/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:34:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 21:01:22 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

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
        void setType( std::string type );
        virtual void makeSound() const;
};
#endif