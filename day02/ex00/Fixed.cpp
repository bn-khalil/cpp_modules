/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:11 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/16 13:01:58 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractional = 8;

Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point_number = 0;
}

Fixed::Fixed( const Fixed& diff ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = diff;
}

Fixed& Fixed::operator = ( const Fixed& diff ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &diff)
        this->fixed_point_number = diff.fixed_point_number;
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point_number;
}

void Fixed::setRawBits( int const raw ) {
    this->fixed_point_number = raw;
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}