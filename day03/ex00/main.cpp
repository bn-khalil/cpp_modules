/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:07:25 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/18 15:52:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap a("khalil");
    a.attack("bn");
    a.takeDamage(3);
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.attack("bn");
    a.takeDamage(3);
    a.takeDamage(3);
    a.takeDamage(3);
    a.takeDamage(3);
    a.takeDamage(3);
    a.beRepaired(3);
    return (0);
}
