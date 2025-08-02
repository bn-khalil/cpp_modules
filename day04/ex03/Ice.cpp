/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:13:01 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/02 13:43:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria( "ice" ) {}

Ice::Ice( Ice const & other ) {
    *this = other;
}

Ice & Ice::operator=( const Ice & other) {
    if (&other != this) {
        this->type = other.type;
    }
    return ( *this );
}

Ice::~Ice(){}

AMateria* Ice::clone() const{
    return ( new Ice() );
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
