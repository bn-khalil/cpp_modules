/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:55:13 by kben-tou          #+#    #+#             */
/*   Updated: 2025/09/20 20:55:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat b1("bn", 2);
        Bureaucrat b2("m1", 3);

        Bureaucrat* b3 = new Bureaucrat("sp", 20);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        Form f1("formF1", false, 20, 15);
        Form f2("formF2", false, 5, 50);

        Form *f3 = new Form(f1);

        std::cout << *f3 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        f2.beSigned(b2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << *f3 << std::endl;
        b3->signForm(*f3);
        std::cout << *f3 << std::endl;

        // incorrect cases

        Form f8("formF3", false, 0, 15);
        Form f9("formF4", false, 5, 200);

        Form f10("formF5", false, 1, 1);
        f10.beSigned(b1);
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}