/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:20 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/07 18:25:21 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char *av[]){

    if (ac != 2) {
        std::cout << "Error: " << "invalid arguments" << std::endl;
        return 0;
    }
    ScalarConverter::convert(std::string(av[1]));
    return 0;
}