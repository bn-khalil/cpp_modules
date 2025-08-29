/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:52:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/08/29 10:07:28 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

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

        std::string getName();
        int get_is_singed();
        int get_grade_sing();
        int get_grade_execute();
        void beSigned( Bureaucrat bureaucrat );
};

#endif