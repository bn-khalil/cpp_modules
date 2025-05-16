/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:16:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 23:20:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon() {}

Weapon::Weapon(std::string type): type( type ) {}

void    Weapon::setType( std::string type ) {
    this->type = type;
}

std::string Weapon::getType( void ) {
    return ( this->type );
}