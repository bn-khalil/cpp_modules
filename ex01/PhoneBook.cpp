/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:03:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/14 15:05:54 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): last_position(0), contact_size(0) {}

void PhoneBook::add_contact(std::string firstname, std::string lastname, \
std::string number, std::string nickname, std::string darkestsecret) {
        if (last_position >= 8)
            last_position = 0;
        this->contact[last_position].set_phone_number(number);
        this->contact[last_position].set_firstname(firstname);
        this->contact[last_position].set_lastname(lastname);
        this->contact[last_position].set_nickname(nickname);
        this->contact[last_position].set_darkest_secret(darkestsecret);
        if (this->last_position < 8) {
            this->last_position++; 
        }
        if (this->last_position < 8 && this->contact_size < 8) {
            this->contact_size++;
        }
};

Contact* PhoneBook::get_contacts(void) {
    return (this->contact);
}

void print_white_spaces(int number) {
    for( int i = 0; i < number; i++)  {
        std::cout << " ";
    }
}

int PhoneBook::get_size() {
    return (this->contact_size);
}

Contact PhoneBook::find(int index) {
   for(int i = 0; i < this->contact_size; i++) {
        if (i + 1 == index) {
            return (this->contact[i]);
        }
   }
   return (Contact());
}

void PhoneBook::display_contact(void) {
    if (this->contact_size <= 0) {
        std::cout<< "there is no contacts available!"<<std::endl;
        return ;
    }
    std::cout<<"---------------------------------------------"<<std::endl;
    for (size_t i = 0; i < this->contact_size; i++)
    {
        std::cout << '|';
        std::cout << i + 1;
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
    std::cout<<"---------------------------------------------"<<std::endl;
}