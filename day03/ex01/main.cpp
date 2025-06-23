/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/23 09:53:27 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap b("bn");

    b.takeDamage(12);
    b.takeDamage(1);
    b.takeDamage(30);
    b.takeDamage(7);
    b.beRepaired(7);
    b.takeDamage(7);
    b.takeDamage(50);
    b.attack("bn");
    return (0);
}
