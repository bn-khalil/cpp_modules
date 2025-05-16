/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:14:22 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 23:19:56 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>


class Weapon {
    private:
        std::string type;

    public:
        Weapon( std::string type );
        ~Weapon();

        void    setType( std::string type );
        std::string getType( void );
};

#endif
