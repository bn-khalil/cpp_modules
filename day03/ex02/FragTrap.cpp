/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/23 11:38:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
    std::cout << "FragTrap constructor colled!" << std::endl;
};

FragTrap::FragTrap( std::string name ) {
    std::cout << "FragTrap params constructor called!" << std::endl;
    this->Name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap& diff ) {
    std::cout << "Copy FragTrap constructor called!" << std::endl;
    *this = diff;
}

FragTrap& FragTrap::operator= ( const FragTrap &diff ) {
    if (this != &diff)
    {
        this->Name = diff.Name;
        this->hit_points = diff.hit_points;
        this->energy_points = diff.energy_points;
        this->attack_damage = diff.attack_damage;
    }
    return ( *this );
}

void FragTrap::highFivesGuys( void ) {
    std::cout << this->Name << "FragTrap says 🙌" << std::endl;
}

FragTrap::~FragTrap( void ) {
    std::cout << this->Name << "FragTrap destructor colled!" << std::endl;
};