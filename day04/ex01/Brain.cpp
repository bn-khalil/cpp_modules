/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:32:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/20 13:33:04 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Constructor Called!" << std::endl;
    this->index = 0;
}

Brain::Brain( const Brain &other ) {
    std::cout << "Brain Copy Constructor Called!" << std::endl;
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
    std::cout << "Brain Destructor Called!" << std::endl;
}

std::string *Brain::getIdeas() {
    return ( this->ideas );
}

void Brain::setIdea( std::string idea ) {
    if (this->index < 100) {
        this->ideas[index] = idea;
        index++;
    }
}