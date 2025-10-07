/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:26 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/07 19:40:57 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter Default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& diff ) {
    std::cout << "Copy ScalarConverter constructor called!" << std::endl;
    (void)diff;
}

ScalarConverter& ScalarConverter::operator= ( const ScalarConverter &diff ) {
    std::cout << "Copy ScalarConverter assinement operator called!" << std::endl;
    (void)diff;
    return ( *this );
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter Destructor called!" << std::endl;
}

void ScalarConverter::convert( std::string arg ) {

    if (arg.empty()) {
        displayImpossible();
        return ;
    }
    if (isPseudo(arg)) {
        displayPseudoLiterals(arg);
        return ;
    }
    try
    {
        if (isNum(arg))
            displayInterger(std::stoi(arg));
        else if (arg.size() <= 1)
            printChar(arg);
        else if (isFloat(arg))
            displayFloat(std::stof(arg));
        else if (isDouble(arg))
            displayDouble(std::stod(arg));
        else
            displayImpossible();
    }
    catch(const std::exception& e)
    {
        (void) e;
        displayImpossible();
    }
}
