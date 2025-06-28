/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/28 21:05:28 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    ScavTrap robot1("bn");
    
    robot1.guardGate();
    robot1.attack("wall");
    robot1.attack("tree");
    robot1.takeDamage(50);
    robot1.beRepaired(10);
    robot1.takeDamage(200);
    robot1.attack("tree");
    return (0);
}
