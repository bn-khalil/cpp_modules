/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:51:12 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/18 15:13:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl a;
    if (ac != 2) {
        std::cout << "invalid number of arguments!" << std::endl;
        return ( 1 );
    }
    if (std::string(av[1]) == "DEBUG" \
    || std::string(av[1]) == "INFO" \
    || std::string(av[1]) == "WARNING" \
    || std::string(av[1]) == "ERROR")
        a.complain(av[1]);
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    return 0;
}
