/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 12:27:57 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/02 13:44:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "AMateria Constructor called!" << std::endl;
}

AMateria::AMateria( std::string const & type ): type( type ) {
    std::cout << "AMateria params Constructor called!" << std::endl;
}

AMateria::AMateria( AMateria const & other  ) {
    *this = other;
}

AMateria& AMateria::operator=( const AMateria &other ) {
    if ( this != &other)
        this->type = other.type;
    return ( *this );
}

AMateria::~AMateria() {
    // std::cout << "AMateria Distructor called!" << std::endl;
}

std::string const & AMateria::getType() const {
    return ( this->type );   
}

void AMateria::use(ICharacter& target) {
    (void)target;
    std::cout << "there is no materia" << std::endl;
}
