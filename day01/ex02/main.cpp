/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:46:09 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/25 15:27:41 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {

    std::string str_val = "HI THIS IS BRAIN";
    std::string *stringPTR = &str_val;
    std::string &stringREF = str_val;

    std::cout << "The memory address of the string variable : " << &str_val << std::endl;
    std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;

    std::cout << "The value of the string variable          : " << str_val << std::endl;
    std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;

    return ( 0 );
}