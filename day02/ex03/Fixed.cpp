/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:11 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/17 14:04:43 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fractional = 8;

Fixed::Fixed( void ) {

    this->fixed_point_number = 0;
}

Fixed::Fixed( const int num ) {

    this->fixed_point_number = roundf( num * 256 );
}

Fixed::Fixed( const float num ) {

    this->fixed_point_number = roundf( num * 256 );
}

Fixed::Fixed( const Fixed& diff ) {

    *this = diff;
}

Fixed& Fixed::operator = ( const Fixed& diff ) {

    if (this != &diff)
        this->fixed_point_number = diff.fixed_point_number;
    return ( *this );
}

int Fixed::getRawBits( void ) const {

    return ( this->fixed_point_number );
}

void Fixed::setRawBits( int const raw ) {

    this->fixed_point_number = raw;
}

float Fixed::toFloat( void ) const {
    return ( this->fixed_point_number / 256.0f );
}

int Fixed::toInt( void ) const {
    return ( this->fixed_point_number >> fractional );
}

Fixed::~Fixed( void ) {

}

std::ostream& operator << ( std::ostream& cout, const Fixed& fixed ) {
    cout << fixed.toFloat();
    return ( cout );
}

bool Fixed::operator == ( const Fixed& diff ) const {
    if (this->toFloat() == diff.toFloat())
        return ( true );
    return (false);
}

bool Fixed::operator != ( const Fixed& diff ) const {
    if (this->toFloat() != diff.toFloat())
        return ( true );
    return (false);
}

bool Fixed::operator <= ( const Fixed& diff ) const {
    if (this->toFloat() <= diff.toFloat())
        return ( true );
    return (false);
}

bool Fixed::operator >= ( const Fixed& diff ) const {
    if (this->toFloat() >= diff.toFloat())
        return ( true );
    return (false);
}

bool Fixed::operator > ( const Fixed& diff ) const {
    if (this->toFloat() > diff.toFloat())
        return ( true );
    return (false);
}
bool Fixed::operator < ( const Fixed& diff ) const {
    if (this->toFloat() < diff.toFloat())
        return ( true );
    return (false);
}

Fixed Fixed::operator + ( const Fixed& diff ) {
    return ( Fixed( this->toFloat() + diff.toFloat() ) );
}

Fixed Fixed::operator - ( const Fixed& diff ) {
    return ( Fixed( this->toFloat() - diff.toFloat() ) );
}

Fixed Fixed::operator * ( const Fixed& diff ) {
    return ( Fixed( this->toFloat() * diff.toFloat() ) );
}

Fixed Fixed::operator / ( const Fixed& diff ) {
    return ( Fixed( this->toFloat() / diff.toFloat() ) );
}

Fixed Fixed::operator ++ ( int ) {
    Fixed tmp = *this;
    ++this->fixed_point_number;
    return ( tmp );
}

Fixed Fixed::operator -- ( int ) {
    Fixed tmp = *this;
    --this->fixed_point_number;
    return ( tmp );
}

Fixed Fixed::operator ++ ( void ) {
    this->fixed_point_number++;
    return ( *this );
}

Fixed Fixed::operator -- ( void ) {
    this->fixed_point_number--;
    return ( *this );
}

Fixed& Fixed::min( Fixed& first, Fixed& second ) {
    if ( first < second )
        return ( first );
    return ( second );
}

const Fixed& Fixed::min( const Fixed& first, const Fixed& second ) {
    if ( first < second )
        return ( first );
    return ( second );
}

Fixed& Fixed::max( Fixed& first, Fixed& second ) {
    if ( first > second )
        return ( first );
    return ( second );
}

const Fixed& Fixed::max( const Fixed& first, const Fixed& second ) {
    if ( first > second )
        return ( first );
    return ( second );
}