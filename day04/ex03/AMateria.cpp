/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:27:57 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/21 22:48:53 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria( std::string const & type ): type( type ) {}

AMateria::AMateria( AMateria const & other  ) {
    *this = other;
}

AMateria& AMateria::operator=( const AMateria &other ) {
    if ( this != &other)
        this->type = other.type;
    return ( *this );
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return ( this->type );   
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "there is no materia" << std::endl;
}
