/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:44:27 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/20 11:02:09 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try
    {
        Bureaucrat president_bn("pres_bn", 5);
        Bureaucrat co_president("co_bn", 15);
        Bureaucrat director("lil", 25);
        Bureaucrat co_director("kh", 50);

        std::cout << president_bn << std::endl;
        std::cout << director << std::endl;
        std::cout << co_director << std::endl;
        std::cout << co_president << std::endl;

        PresidentialPardonForm F1("jon");
        RobotomyRequestForm F2("clup");
        ShrubberyCreationForm F3("tree");

        std::cout << F1 << std::endl;
        std::cout << F2 << std::endl;
        std::cout << F3 << std::endl;

        // correct cases:
        std::cout << "==============================" << std::endl;
        co_president.signForm(F1);
        std::cout << F1 << std::endl;
        president_bn.executeForm(F1);
        std::cout << "==============================" << std::endl;

        co_director.signForm(F2);
        std::cout << F2 << std::endl;
        director.executeForm(F2);
        std::cout << "==============================" << std::endl;

        co_director.signForm(F3);
        std::cout << F3 << std::endl;
        co_director.executeForm(F3);
        std::cout << "==============================" << std::endl;

        // cases that will throw exceptions:

        // std::cout << "==============================" << std::endl;
        // president_bn.signForm(F1);
        // std::cout << F1 << std::endl;
        // co_president.executeForm(F1);

        // std::cout << "==============================" << std::endl;
        // co_director.signForm(F2);
        // std::cout << F2 << std::endl;
        // co_director.executeForm(F2);
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}