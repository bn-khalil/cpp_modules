/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:52:19 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/14 21:46:59 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
        int last_position;
        int contact_size;
    public:
        PhoneBook();
        void add_contact(std::string firstname, std::string lastname, \
        std::string number, std::string nickname, std::string darkestsecret);
        void display_contact(void);
        int get_size();
        Contact find(int index);
        Contact* get_contacts(void);
};
#endif
