/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:11 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/16 18:39:50 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional = 8;

Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point_number = 0;
}

Fixed::Fixed( const int num ) {
    std::cout<<"Int constructor called\n";
    this->fixed_point_number = roundf( num * 256 );
}

Fixed::Fixed( const float num ) {
    std::cout << "Float constructor called\n";
    this->fixed_point_number = roundf( num * 256 );
}

Fixed::Fixed( const Fixed& diff ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = diff;
}

Fixed& Fixed::operator = ( const Fixed& diff ) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &diff)
        this->fixed_point_number = diff.fixed_point_number;
    return ( *this );
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return ( this->fixed_point_number );
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point_number = raw;
}

float Fixed::toFloat( void ) const {
    return ( this->fixed_point_number / 256.0f );
}

int Fixed::toInt( void ) const {
    return ( this->fixed_point_number >> fractional );
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator << ( std::ostream& cout, const Fixed& fixed ) {
    cout << fixed.toFloat();
    return ( cout );
}
