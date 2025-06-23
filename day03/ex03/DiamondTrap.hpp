/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/23 13:54:12 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string name;

    public :
        DiamondTrap( void );
        DiamondTrap( std::string name );
        DiamondTrap( const DiamondTrap& diff );
        DiamondTrap& operator=( const DiamondTrap &diff );
        ~DiamondTrap( void );
        
        void attack( const std::string& targe );
        void whoAmI( void );
};

#endif