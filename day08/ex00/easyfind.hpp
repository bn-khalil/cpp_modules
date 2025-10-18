/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:55:29 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/08 12:00:41 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
std::string easyfind(const T & con, int n) {
   if (std::find(con.begin(), con.end(), n) == con.end())
        return "item not found!";
    return "item found!";
}


#endif