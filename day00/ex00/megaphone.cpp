/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:58:45 by kben-tou          #+#    #+#             */
/*   Updated: 2025/06/24 15:19:13 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
    while (av[i])
    {
        int j = 0;
        while (av[i][j]) {
            av[i][j] = std::toupper(av[i][j]);
            j++;
        }
        std::cout << av[i] ;
        i++;
    }
    std:: cout << std::endl;
    return (0);
}