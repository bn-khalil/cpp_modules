/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:10:33 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 16:16:37 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal( std::string type);
        WrongAnimal( const WrongAnimal &other );
        WrongAnimal &operator=( const WrongAnimal &other );
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};
#endif