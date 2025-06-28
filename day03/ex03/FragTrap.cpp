/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 23:03:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap() {
    std::cout << "FragTrap constructor colled!" << std::endl;
};

FragTrap::FragTrap( std::string name ): ClapTrap( name ) {
    std::cout << "FragTrap params constructor called!" << std::endl;
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap& diff ): ClapTrap( diff ) {
    std::cout << "Copy FragTrap constructor called!" << std::endl;
    *this = diff;
}

FragTrap& FragTrap::operator= ( const FragTrap &diff ) {
    if (this != &diff)
    {
        this->name = diff.name;
        this->hit_points = diff.hit_points;
        this->energy_points = diff.energy_points;
        this->attack_damage = diff.attack_damage;
    }
    return ( *this );
}

void FragTrap::highFivesGuys( void ) {
    std::cout << this->name << "FragTrap sands a positive high-fives" << std::endl;
}

FragTrap::~FragTrap( void ) {
    std::cout << "FragTrap destructor colled!" << std::endl;
};
