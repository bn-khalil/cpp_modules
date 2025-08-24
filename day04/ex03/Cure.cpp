/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:48:13 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/23 08:51:20 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria( "cure" ) {}

Cure::Cure( Cure const & other ) {
    *this = other;
}

Cure & Cure::operator=( const Cure & other) {
    if (&other != this) {
        this->type = other.type;
    }
    return ( *this );
}

Cure::~Cure(){}

AMateria* Cure::clone() const{
    return ( new Cure() );
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
