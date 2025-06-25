/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:53 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 09:49:41 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << "the Zombie: " << this->name << " is dead" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << this->name << " :" << "BraiiiiiiinnnzzzZ..." << std::endl;
}