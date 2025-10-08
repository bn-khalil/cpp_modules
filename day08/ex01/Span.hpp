/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:55:19 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 13:41:04 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
    private:
        std::vector<int> ints;
        unsigned int n;
        
    public:
        Span( unsigned int n );
        Span( const Span & other );
        Span & operator = ( Span & other );
        ~Span();

        void addNumber( int n );
        size_t shortestSpan();
        size_t longestSpan();

        class collectionFullException: public std::exception {
            const char *what() const throw();
        };
};

#endif