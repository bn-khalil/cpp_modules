/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:35:13 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 22:04:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) {
    std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) {
    std::cout << "ClapTrap constructor called!" << std::endl;
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap& diff ) {
    std::cout << "Copy ClapTrap constructor called!" << std::endl;
    *this = diff;
}

ClapTrap& ClapTrap::operator= ( const ClapTrap &diff ) {
    if (this != &diff)
    {
        this->name = diff.name;
        this->hit_points = diff.hit_points;
        this->energy_points = diff.energy_points;
        this->attack_damage = diff.attack_damage;
    }
    return ( *this );
}

ClapTrap::~ClapTrap( void ) {
    std::cout << "ClapTrap Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->hit_points <= 0)
    {
        std::cout << this->name << " is dead!" << std::endl;
        return ;
    }
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \<< this->attack_damage << " points of damage! "  << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't attack, No energy or hit points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hit_points <= 0)
    {
        std::cout << this->name << " is dead!" << std::endl;
        return ;
    }
    this->hit_points -= amount;
    if (this->hit_points < 0)
        this->hit_points = 0;
    std::cout << "ClapTrap " << this->name << " takes damage, and lost " << amount << " hit points! " << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hit_points <= 0)
    {
        std::cout << this->name << " is dead!" << std::endl;
        return ;
    }
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points--;
        this->hit_points += amount;
        std::cout << "ClapTrap " << this->name << " recoverd " << amount << " hit points! " << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't repair!" << std::endl;
}
