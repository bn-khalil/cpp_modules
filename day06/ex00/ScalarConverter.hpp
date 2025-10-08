/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:29 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 09:45:40 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALCONVERTER_H
#define SCALCONVERTER_H

#include <iostream>
#include "Utils.hpp"

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter &other );
    public:
        ScalarConverter& operator= ( const ScalarConverter &diff );
        ~ScalarConverter();

        static void convert( std::string arg );
};

#endif