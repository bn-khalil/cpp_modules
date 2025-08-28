/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/28 21:48:34 by kben-tou         ###   ########.fr       */
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
        Form( const std::string name, bool is_singed, int grade_sing, int grade_execute );
        Form( const Form &other );
        Form &operator=( Form &other );
        ~Form();

        void beSigned( Bureaucrat bureaucrat );
};

#endif