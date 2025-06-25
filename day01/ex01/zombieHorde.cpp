/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:41:39 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 15:30:34 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    
    if (N <= 0)
    {
        Zombie* ret = NULL;
        return ( ret );
    }
    Zombie* z_s = new Zombie[N];
    int i = -1;
    while ( ++i < N )
        z_s[i].setname( name );
    return ( z_s );
}