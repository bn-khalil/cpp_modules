/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:25:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 09:57:37 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {

    Data data;
    data.c = 'a';
    data.i = 0;
    data.b = true;
    data.l = 12.2;

    uintptr_t ptrint = Serializer::serialize(&data);

    std::cout << "data address before casting!" << std::endl;
    std::cout << &data << std::endl;
    std::cout << "data address casting to decimal!" << std::endl;
    std::cout << ptrint << std::endl;
    std::cout << "data address casting from decimal!" << std::endl;
    std::cout << Serializer::deserialize(ptrint) << std::endl;

    return 0;
}