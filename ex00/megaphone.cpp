/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:58:45 by kben-tou          #+#    #+#             */
/*   Updated: 2025/04/28 10:31:42 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    int i = 1;

    if (ac == 1)
        return (cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl, 0);
    while (av[i])
    {
        int j = 0;
        while (av[i][j]) {
            if ((av[i][j] >= 'a' && av[i][j] <= 'z'))
                av[i][j] -= 32;
            j++;
        }
        cout << av[i];
        i++;
    }
    return (0);
}