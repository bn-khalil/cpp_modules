/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 22:04:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>

class ClapTrap
{
    protected :
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;

    public :
        ClapTrap( void );
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap& diff );
        ClapTrap& operator=( const ClapTrap &diff );
        ~ClapTrap( void );

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif