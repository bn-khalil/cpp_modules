/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:52:19 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/13 18:55:29 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
        int last_position;
    public:
        PhoneBook();
        ~PhoneBook(){};
        void add_contact(std::string firstname, std::string lastname, std::string number, std::string nickname, std::string darkestsecret);
        void display_contact(void);
        Contact get_single_contact();
        Contact* get_contacts(void);
};
#endif
