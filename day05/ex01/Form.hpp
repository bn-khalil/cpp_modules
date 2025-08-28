/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/28 11:29:04 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>

class Form
{
    private:
        const std::string name;
        bool is_singed;
        const int grade_sing;
        const int grade_execute;
    public:
        Form();
        Form( const std::string name, int grade );
        Form( Form &other );
        Form &operator=( Form &other );
        ~Form();
};

#endif