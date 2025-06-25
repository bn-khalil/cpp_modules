/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:24:30 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 15:32:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* z_s = zombieHorde( -3, "khalil" );
    if (!z_s)
        return ( 0 );

    for (int i = 0; i < 3; i++) {
        z_s[i].announce();
    }
    delete []z_s;
    return ( 0 );
}