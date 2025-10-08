/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:28:47 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 10:11:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "DrivedA.hpp"
#include "DrivedB.hpp"
#include "DrivedC.hpp"

Base * generate(void) {
    int rand = std::time(NULL) % 3;
    if (rand == 0)
        return new DrivedA();
    else if (rand == 1)
        return new DrivedB();
    return new DrivedC();
}

void identify(Base* p) {
    if (dynamic_cast<DrivedA*>(p))
        std::cout << "this is an object type DrivedA\n" << std::endl;
    else if (dynamic_cast<DrivedB*>(p))
        std::cout << "this is an object type DrivedB\n" << std::endl;
    else if (dynamic_cast<DrivedC*>(p))
        std::cout << "this is an object type DrivedC\n" << std::endl;
}

void identify(Base& p) {
    try {
        DrivedA driveda = dynamic_cast<DrivedA&>(p);
        (void) driveda;
        std::cout << "this is an object type DrivedA\n" << std::endl;
        return ;
    } catch(std::exception &e ) {}

    try
    {
        DrivedB drivedb = dynamic_cast<DrivedB&>(p);
        (void) drivedb;
        std::cout << "this is an object type DrivedB\n" << std::endl;
        return ;
    }
    catch(const std::exception& e) {}

    try
    {
        DrivedC drivedc = dynamic_cast<DrivedC&>(p);
        (void) drivedc;
        std::cout << "this is an object type DrivedC\n" << std::endl;
        return ;
    }
    catch(const std::exception& e){}
}
