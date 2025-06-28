/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 23:18:00 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap constructor colled!" << std::endl;
};

DiamondTrap::DiamondTrap( std::string name ):ClapTrap( name + "_clap_name"), ScavTrap( name ), FragTrap( name ) {
    std::cout << "DiamondTrap params constructor called!" << std::endl;
    this->_name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& diff ) {
    std::cout << "Copy DiamondTrap constructor called!" << std::endl;
    *this = diff;
}

DiamondTrap& DiamondTrap::operator= ( const DiamondTrap &diff ) {
    if (this != &diff)
    {
        this->name = diff.name;
        this->_name = diff.name;
        this->hit_points = diff.hit_points;
        this->energy_points = diff.energy_points;
        this->attack_damage = diff.attack_damage;
    }
    return ( *this );
}

DiamondTrap::~DiamondTrap( void ) {
    std::cout << "DiamondTrap destructor colled!" << std::endl;
};

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::ClapTrap::attack( target );
}

void DiamondTrap::whoAmI( void ) {
    std::cout << "you are " << this->name << " " << this->_name << std::endl;
}

