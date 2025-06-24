/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:35:21 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/24 15:43:17 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook app;
    Contact *finded;
    std::string att[5];
    std::string opt;
    std::string search;
    int i;

    std::cout<< std::endl <<"             Wellcom to PhoneBook!           "<<std::endl<<std::endl;
    while(1) {
        std::cout<<"============================================="<<std::endl;
        std::cout<<"chose: ADD / SEARCH / EXIT"<<std::endl;
        std::cout<<"---------------------------------------------"<<std::endl;
        std::cout<<"> ";

        if (!std::getline(std::cin, opt))
            break ;

        if (opt == "ADD") {
            std::cout << " - adding new contact" <<std::endl;
            i = 0;
            while (i < 5)
            {
                if (i == 0)
                    std::cout << "Enter your first name: ";
                if (i == 1)
                    std::cout << "Enter your last name: ";
                if (i == 2)
                    std::cout << "Enter your phone number: ";
                if (i == 3)
                    std::cout << "Enter your nickname: ";
                if (i == 4)
                    std::cout << "Enter your darkest secret: ";
                if (!std::getline(std::cin, att[i]))
                    return (1);
                if (att[i].empty()) {
                    std::cout << "The field must not be empty!"<<std::endl;
                    continue;
                }
                i++;
            }
            app.add_contact(att[0], att[1], att[2], att[3], att[4]);
        } else if (opt == "SEARCH") {
            if (app.display_contact())
                continue ;
            while (1){
                std::cout << "Shose contact> ";
                if (!std::getline(std::cin, search))
                    return (1);
                if (search.length() != 1 || search[0] - '0' > 8) {
                    std::cout << "invalid index!" << std::endl;
                    continue;
                }
                finded = app.find(search[0] - '0');
                if (finded == nullptr || finded->get_firstname().empty())
                {
                    std::cout << "the contact not found or the input not valid!"<<std::endl;
                    continue ;
                }
                std::cout << "your first name: " << finded->get_firstname() << std::endl;
                std::cout << "your last name: " << finded->get_lastname() << std::endl;
                std::cout << "your phone number: " << finded->get_phone_number() << std::endl;
                std::cout << "your nickname: " << finded->get_nickname() << std::endl;
                std::cout << "your darkest secret: " << finded->get_darkest_secret() << std::endl;
                break ;
            }
        } else if (opt == "EXIT") {
            break ;            
        }
    }
    return 0;
}
