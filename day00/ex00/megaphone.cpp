/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:58:45 by kben-tou          #+#    #+#             */
/*   Updated: 2025/05/14 20:50:24 by kben-tou         ###   ########.fr       */
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
            if ((av[i][j] >= 'a' && av[i][j] <= 'z'))
                av[i][j] -= 32;
            j++;
        }
        std::cout << av[i];
        i++;
    }
    return (0);
}