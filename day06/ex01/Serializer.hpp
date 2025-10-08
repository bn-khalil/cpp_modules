/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:59 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 09:49:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include "Data.hpp"

class Serializer {

    private:
        Serializer();
        Serializer( const Serializer &other );
    public:
        Serializer& operator= ( const Serializer &diff );
        ~Serializer();

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif