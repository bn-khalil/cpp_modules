/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:58:13 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 12:37:02 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>

int main () {
    
    std::vector<int> vector_numbers;
    std::array<int, 3> array_numbers;

    vector_numbers.push_back(3);
    vector_numbers.push_back(2);
    vector_numbers.push_back(1);
    
    array_numbers[0] = 1;
    array_numbers[1] = 2;
    array_numbers[2] = 3;
    
    std::cout << "|==================================|" << std::endl;
    std::cout << easyfind(vector_numbers, 3) << std::endl;
    std::cout << easyfind(vector_numbers, 20) << std::endl;
    std::cout << easyfind(vector_numbers, 1) << std::endl;
    
    std::cout << "|==================================|" << std::endl;
    std::cout << easyfind(array_numbers, 3) << std::endl;
    std::cout << easyfind(array_numbers, 20) << std::endl;
    std::cout << easyfind(array_numbers, 1) << std::endl;

    return 0;
}