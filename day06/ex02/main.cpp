/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:28:41 by kben-tou          #+#    #+#             */
/*   Updated: 2025/10/07 18:28:42 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "DrivedA.hpp"
#include "DrivedB.hpp"
#include "DrivedC.hpp"
#include "Utils.hpp"

int main(){
    std::cout << "generate Drived object\n" << std::endl;
    Base *hold = generate();

    std::cout << "|======================================|" << std::endl;
    std::cout << "identify Drived type with using pointer: " << std::endl;
    identify(hold);

    std::cout << "|======================================|" << std::endl;
    std::cout << "identify Drived type with using reference: " << std::endl;
    identify(*hold);

    delete hold;
    return 0;
}