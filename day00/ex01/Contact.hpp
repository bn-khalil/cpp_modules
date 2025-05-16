/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:07:19 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/14 21:46:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void set_firstname(std::string);
        void set_lastname(std::string);
        void set_nickname(std::string);
        void set_phone_number(std::string);
        void set_darkest_secret(std::string);
        std::string get_firstname(void);
        std::string get_lastname(void);
        std::string get_nickname(void);
        std::string get_phone_number(void);
        std::string get_darkest_secret(void);
};
#endif