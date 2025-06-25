/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:14:22 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/24 12:25:56 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"


class HumanB {
    private:
        std::string name;
        Weapon      *weapon; 

    public:
        HumanB( std::string name );
        ~HumanB();

        void    attack( void );
        void    setWeapon( Weapon &weapon );
};

#endif
