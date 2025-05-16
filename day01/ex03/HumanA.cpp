/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:37:15 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 23:26:11 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &wp): name( name ), weapon( wp ) {}

HumanA::~HumanA() {};

void    HumanA::attack( void ) {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}