/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:18:44 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 16:10:05 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl\
    << "I really do!" << std::endl << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl\
    << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl\
    << "I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level ) {

    int     i;
    int     choice;
    
    i      = -1;
    choice = -1;
    std::string tys[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    void ( Harl::*com_s[4] )( void ) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    while (++i < 4)
    {
        if (level == tys[i])
        {
            choice = i;
            break ;
        }
    }

    switch (choice) {
        case 0:
            (this->*com_s[0])();
        case 1:
            (this->*com_s[1])();
        case 2:
            (this->*com_s[2])();
        case 3:
            (this->*com_s[3])();
        default:
            break;
    }
}
