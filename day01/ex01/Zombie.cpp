/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:53 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 17:33:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie() {
    std::cout << "the zombie: " << this->name << " is dead" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << this->name << " :" << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname( std::string name ) {
    this->name = name;
}
