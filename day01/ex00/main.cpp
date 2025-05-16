/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:24:30 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/16 16:24:36 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // test create zombies and destroy them on the stack;
    randomChump("fred");
    
    // test create zombies and destroy them on the heap;
    Zombie* zombie_1 = newZombie("mike");
    zombie_1->announce();

    Zombie* zombie_2 = newZombie("bn");
    zombie_2->announce();

    delete zombie_1;
    delete zombie_2;
    return ( 0 );
}