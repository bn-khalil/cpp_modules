/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:28:51 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/07 18:28:52 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif