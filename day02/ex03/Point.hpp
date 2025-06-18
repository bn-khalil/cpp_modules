/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:17:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/18 10:30:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;
    public:
        Point();
        Point( const float x, const float y );
        Point( const Point& diff );
        Point& operator = ( const Point& diff );
        ~Point();

        Fixed getX();
        Fixed getY();
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
