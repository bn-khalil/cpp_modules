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

template <typename T>

void easyfind(T con, int n) {
    bool found = false;
    
    for (size_t i = 0; i < con.size(); i++) {
        if (n == con.at(i))
            found = true;
    }
    if (!found)
        throw numberNotFoundException();
}

const char * numberNotFoundException::what() const throw() {
    return "integer not found!";
}

int main () {
    
    std::vector<int> vector_numbers;
    std::array<int, 3> array_numbers;

    vector_numbers.push_back(1);
    vector_numbers.push_back(2);
    vector_numbers.push_back(3);
    
    array_numbers[0] = 1;
    array_numbers[1] = 2;
    array_numbers[2] = 3;
    
    easyfind(array_numbers, 4);
    return 0;
}