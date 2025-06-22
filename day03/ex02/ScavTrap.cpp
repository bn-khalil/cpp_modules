/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:58 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/22 21:18:31 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
    std::cout << "ScavTrap constructor colled!" << std::endl;
};

ScavTrap::ScavTrap( std::string name ) {
    std::cout << "ScavTrap params constructor called!" << std::endl;
    this->Name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& diff ) {
    std::cout << "Copy ScavTrap constructor called!" << std::endl;
    *this = diff;
}

ScavTrap& ScavTrap::operator= ( const ScavTrap &diff ) {
    if (this != &diff)
    {
        this->Name = diff.Name;
        this->hit_points = diff.hit_points;
        this->energy_points = diff.energy_points;
        this->attack_damage = diff.attack_damage;
    }
    return ( *this );
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap( void ) {
    std::cout << "ScavTrap destructor colled!" << std::endl;
};