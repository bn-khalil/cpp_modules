/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:56 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/07 18:25:57 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer Default constructor called!" << std::endl;
}

Serializer::Serializer( const Serializer& diff ) {
    std::cout << "Copy Serializer constructor called!" << std::endl;
    (void)diff;
}

Serializer& Serializer::operator= ( const Serializer &diff ) {
    std::cout << "Copy Serializer assiment operator called!" << std::endl;
    (void)diff;
    return ( *this );
}

Serializer::~Serializer() {
    std::cout << "ScalarConverter Destructor called!" << std::endl;
}

uintptr_t Serializer::serialize( Data* ptr ) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}