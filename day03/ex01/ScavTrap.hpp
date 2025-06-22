/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:43:58 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/22 21:10:06 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap( void );
        ScavTrap( std::string name );
        ScavTrap( const ScavTrap& diff );
        ScavTrap& operator= ( const ScavTrap &diff );
        ~ScavTrap( void );

        void guardGate();
};

#endif