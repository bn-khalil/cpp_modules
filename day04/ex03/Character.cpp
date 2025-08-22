/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:37:39 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/22 12:05:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 4; i++)
        this->inventories[i] = NULL;
    this->materia_numbers = 0;
}

Character::Character( std::string const & name ) {
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventories[i] = NULL;
    this->materia_numbers = 0;
}

Character::Character( Character const & other  ) {
    *this = other;
}

Character& Character::operator= ( const Character &other ) {
    if ( this != &other) {
        this->name = other.name;
        for (int i = 0; i < 4; i++) {
            if (this->inventories[i])
                delete this->inventories[i];
            if (other.inventories[i])
                this->inventories[i] = other.inventories[i]->clone();
            else
                this->inventories[i] = NULL;
        }
        this->materia_numbers = other.materia_numbers;   
    }
    return ( *this );
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (this->inventories[i]) {
            int j = i + 1;
            while (j < 4)
            {
                if (this->inventories[i] == this->inventories[j])
                    this->inventories[j] = NULL;
                j++;
            }
            delete this->inventories[i];
            this->inventories[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return ( this->name );
}

void Character::equip(AMateria* m) {
    if (this->materia_numbers >= 4)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if ( this->inventories[i] == NULL ) {
            this->inventories[i] = m;
            this->materia_numbers++;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if ( idx >= 0 && idx < 4 && this->inventories[idx] != NULL ) {
        this->inventories[idx] = NULL;
        this->materia_numbers--;
    }
}

void Character::use(int idx, ICharacter& target) {
    if ( idx >= 0 && idx < 4 && this->inventories[idx] != NULL) {
        this->inventories[idx]->use(target);
    }
}