/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/16 17:37:04 by kben-tou         ###   ########.fr       */
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
        Fixed& operator = ( const Fixed& diff);
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<< (std::ostream& cout , const Fixed& fixed);

#endif