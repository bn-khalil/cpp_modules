/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:30:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/31 16:33:46 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int fixed_point_number;
        static const int fractional;

    public:
        Fixed( void );
        Fixed( const Fixed& diff );
        Fixed& operator = ( const Fixed& diff);
        ~Fixed( void );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif