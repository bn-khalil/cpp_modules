/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:17:01 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/18 10:19:47 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point( float x, float y ) {
    this->x = x;
    this->y = y;
}

Point::Point( const Point& diff ) {
    *this = diff;
}

Point& Point::operator = ( const Point& diff ) {
    if (this != &diff)
    {
        this->x = diff.x;
        this->y = diff.y;
    }
    return ( *this );
}

Fixed Point::getX() {
    return ( this->x );
}

Fixed Point::getY() {
    return ( this->y );
}

Point::~Point(){}
