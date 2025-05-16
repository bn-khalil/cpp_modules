/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:07:28 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/14 16:07:29 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_firstname(std::string firstname) {
    this->firstname = firstname;
}
void Contact::set_lastname(std::string lastname) {
    this->lastname = lastname;
}
void Contact::set_nickname(std::string nickname) {
    this->nickname = nickname;
}
void Contact::set_phone_number(std::string phone_number) {
    this->phone_number = phone_number;
}
void Contact::set_darkest_secret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}
std::string Contact::get_firstname(void) {
    return this->firstname;
};
std::string Contact::get_lastname(void) {
    return this->lastname;
};
std::string Contact::get_nickname(void) {
    return this->nickname;
};
std::string Contact::get_phone_number(void) {
    return this->phone_number;
};
std::string Contact::get_darkest_secret(void) {
    return this->darkest_secret;
};