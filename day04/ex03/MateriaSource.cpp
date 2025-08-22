/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:32:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/22 11:47:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->backUp[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & other ) {
    *this = other;
}

MateriaSource & MateriaSource::operator=( const MateriaSource & other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++)
        {
            if (this->backUp[i])
                delete this->backUp[i];
            if (other.backUp[i])
                this->backUp[i] = other.backUp[i]->clone();
            else
                this->backUp[i] = NULL;
        }
    }
    return ( *this );
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
        delete this->backUp[i];
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->backUp[i]) {
            this->backUp[i] = materia;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    AMateria *new_materia = NULL;

    for (int i = 0; i < 4; i++)
    {
        if (this->backUp[i] && this->backUp[i]->getType() == type) {
            new_materia = this->backUp[i]->clone();
            return ( new_materia );
        }
    }
    return ( NULL );
}