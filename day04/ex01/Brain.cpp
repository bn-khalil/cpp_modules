/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:32:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/01 18:28:24 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    //
}

Brain::Brain( const Brain &other ) {
    *this = other;
}

Brain& Brain::operator=( const Brain &other ) {
    if ( this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return ( *this );
}

Brain::~Brain() {
    //
}

std::string *Brain::getIdeas() {
    return ( this->ideas );
}