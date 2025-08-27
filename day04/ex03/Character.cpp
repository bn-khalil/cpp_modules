/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:37:39 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/25 14:21:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 100; i++) {
        if ( i < 4 )
            this->inventories[i] = NULL;
        this->store[i] = NULL;
    }
    this->materia_numbers = 0;
    this->number_of_backup = 0;
}

Character::Character( std::string const & name ) {
    this->name = name;
    for (int i = 0; i < 100; i++) {
        if ( i < 4 )
            this->inventories[i] = NULL;
        this->store[i] = NULL;
    }
    this->materia_numbers = 0;
    this->number_of_backup = 0;
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
        this->number_of_backup = other.number_of_backup;
    }
    return ( *this );
}

Character::~Character() {
    for (int i = 0; i < 100; ++i) {
        if (this->store[i]) {
            int j = i + 1;
            while (j < 4)
            {
                if (this->store[i] == this->store[j])
                    this->store[j] = NULL;
                j++;
            }
            delete this->store[i];
            this->store[i] = NULL;
        }
    }
}

std::string const & Character::getName() const {
    return ( this->name );
}

void Character::equip(AMateria* m) {
    if (this->materia_numbers >= 4) {
        if (m)
            delete m;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if ( this->inventories[i] == NULL ) {
            this->inventories[i] = m;
            if (this->store[number_of_backup % 100])
                delete this->store[number_of_backup % 100];
            this->store[number_of_backup % 100] = m;
            this->number_of_backup++;
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
