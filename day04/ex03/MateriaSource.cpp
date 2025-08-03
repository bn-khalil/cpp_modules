/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:32:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/03 11:36:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): {}

MateriaSource::MateriaSource( MateriaSource const & other ) {
    *this = other;
}

MateriaSource & MateriaSource::operator=( const MateriaSource & other) {
    return ( *this );
}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria*) {
    
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    
}