/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:35:21 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/13 23:28:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
    PhoneBook app;
    std::string att[5];
    std::string opt;
    // book.add_contact("sdfsd1sdjksdfsd", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd2", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd3", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd4", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd123", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd223", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd43", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd54", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd16", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd72", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd38", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd04", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd04", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd04", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("sdfsd0400", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.add_contact("khalilbentouda", "sdfs", "sdfs", "sdfsd", "sdf");
    // book.display_contact();
    while(1) {
        std::cout<<"Wellcom to PhoneBook!"<<std::endl;
        std::cout<<"chose an action: ADD, SEARCH, EXIT"<<std::endl;

        std::getline(std::cin, opt);
        if (opt == "ADD") {
            std::cout << " - adding new contact" <<std::endl;
            std::cout << "enter your first name: ";
            std::getline(std::cin, att[0]);
            std::cout << "enter your last name: ";
            std::getline(std::cin, att[1]);
            std::cout << "enter your phone number: ";
            std::getline(std::cin, att[2]);
            std::cout << "enter your nickname: ";
            std::getline(std::cin, att[3]);
            std::cout << "enter your darkest secret: ";
            std::getline(std::cin, att[4]);
            app.add_contact(att[0], att[1], att[2], att[3], att[4]);
        } else if (opt == "SEARCH") {
            app.display_contact();
        } else if (opt == "EXIT") {
            break ;            
        }
    }
    return 0;
}
