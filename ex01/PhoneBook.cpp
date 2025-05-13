/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:03:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/13 23:26:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): last_position(0) {}

void PhoneBook::add_contact(std::string firstname, std::string lastname, \
std::string number, std::string nickname, std::string darkestsecret) {
        this->contact[last_position].set_phone_number(number);
        this->contact[last_position].set_firstname(firstname);
        this->contact[last_position].set_lastname(lastname);
        this->contact[last_position].set_nickname(nickname);
        this->contact[last_position].set_darkest_secret(darkestsecret);
        if (this->last_position < 6)
            this->last_position++;
};

Contact* PhoneBook::get_contacts(void) {
    return (this->contact);
}

void print_white_spaces(int number) {
    for( int i = 0; i < number; i++)  {
        std::cout << " ";
    }
}

void PhoneBook::display_contact(void) {
    for (size_t i = 0; i <= this->last_position; i++)
    {
        std::cout << '|';
        std::cout << i ;
        print_white_spaces(9);
        if (this->contact[i].get_firstname().length() > 10)
            std::cout << "|" << this->contact[i].get_firstname().substr(0, 9) << ".";
        else
        {
            std::cout << "|" << this->contact[i].get_firstname();
            print_white_spaces(10 - this->contact[i].get_firstname().length());
        }
        if (this->contact[i].get_lastname().length() > 10)
            std::cout << "|" << this->contact[i].get_lastname().substr(0, 9) << ".";
        else
        {
            std::cout << "|" << this->contact[i].get_lastname();
            print_white_spaces(10 - this->contact[i].get_lastname().length());
        }
        if (this->contact[i].get_nickname().length() > 10)
            std::cout << "|" << this->contact[i].get_nickname().substr(0, 9) << ".";
        else {
            std::cout << "|" << this->contact[i].get_nickname();
            print_white_spaces(10 - this->contact[i].get_nickname().length());
        }
        std::cout << '|' <<std::endl;
    }
}