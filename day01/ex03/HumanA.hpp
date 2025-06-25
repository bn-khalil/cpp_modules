/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:14:22 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/24 12:26:09 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"


class HumanA {
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA( std::string name, Weapon &wp);
        ~HumanA();

        void    attack( void );
};

#endif
