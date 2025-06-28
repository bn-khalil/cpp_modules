/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:26:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 22:04:45 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_H
#define FLAGTRAP_H
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public :
        FragTrap( void );
        FragTrap( std::string name );
        FragTrap( const FragTrap& diff );
        FragTrap& operator=( const FragTrap &diff );
        ~FragTrap( void );

        void highFivesGuys(void);
};

#endif