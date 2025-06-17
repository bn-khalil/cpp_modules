/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/17 14:00:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int fixed_point_number;
        static const int fractional;

    public:
        Fixed( void );
        Fixed( const int num);
        Fixed( const float num);
        Fixed( const Fixed& diff );
        Fixed& operator = ( const Fixed& diff );

        bool operator == ( const Fixed& diff ) const;
        bool operator != ( const Fixed& diff ) const;
        bool operator <= ( const Fixed& diff ) const;
        bool operator >= ( const Fixed& diff ) const;
        bool operator > ( const Fixed& diff ) const;
        bool operator < ( const Fixed& diff ) const;

        Fixed operator + ( const Fixed& diff );
        Fixed operator - ( const Fixed& diff );
        Fixed operator * ( const Fixed& diff );
        Fixed operator / ( const Fixed& diff );

        Fixed operator ++ ( int );
        Fixed operator -- ( int );
        Fixed operator ++ ( void );
        Fixed operator -- ( void );

        ~Fixed( void );
        
        static Fixed& min( Fixed& first, Fixed& second );
        static const Fixed& min( const Fixed& first, const Fixed& second );
        static Fixed& max( Fixed& first, Fixed& second );
        static const Fixed& max( const Fixed& first, const Fixed& second );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<< (std::ostream& cout , const Fixed& fixed);

#endif